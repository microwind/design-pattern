import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.concurrent.atomic.AtomicBoolean;

/**
 * 响应式编程范式：
 * Flux 是响应式编程的重要组成部分，它关注数据流的变化并基于这些变化触发相应的操作。
 * 在这种范式中，程序不再主动拉取数据，而是对数据变化做出反应，使得数据的流动和操作更加自然和高效。
 *
 * 异步与非阻塞：
 * Flux 流是异步和非阻塞的，操作 Flux 流时不会阻塞主线程，而是在后台线程或事件循环中处理数据。
 * 这使得 Flux 特别适用于高并发和海量数据场景，例如在下载过程中实时读取数据，或在接收请求时边处理边传输结果。
 * 通过异步和非阻塞机制，系统能够在等待数据的同时高效地执行其他任务。
 *
 * 背压机制：
 * Flux 支持背压机制，允许下游订阅者根据自身处理能力控制上游发布者的发送速率。
 * 当订阅者的处理速度低于发布者的数据生成速度时，可以向上游发送信号，请求减缓或暂停数据发送。
 * 背压机制有助于避免资源过载，确保系统的稳定性和可靠性。
 *
 * 冷流与热流：
 * - 冷流：每次订阅冷流时，都会重新创建一个新的数据生产者，并为该订阅者独立发送数据。
 *        这意味着每个订阅者都会接收到相同的元素序列，且彼此之间互不影响。
 * - 热流：热流中的数据生产者是共享的，所有订阅者都接收相同的数据序列。
 */

/**
 * 自定义 Flux 数据流类，支持订阅、发布数据、结束数据流、将冷流转换为热流、连接热流以及 map 和 filter 操作符。
 * 
 * @param <T> 数据流中数据的类型
 */
class FluxData<T> {

    private final List<Consumer<T>> subscribers = new ArrayList<>();
    private boolean completed = false;
    private boolean isCold = true; // 数据流是否为冷流（未连接）
    private final List<T> dataBuffer = new ArrayList<>();
    private final AtomicBoolean isConnected = new AtomicBoolean(false);

    /**
     * 构造函数，创建一个新的数据流实例。
     */
    public FluxData() {
        // System.out.println("数据流创建成功。");
    }

    /**
     * 订阅方法，允许消费者订阅数据流。
     * 如果数据流已经完成，则抛出异常。
     * 如果是冷流，消费者会被添加到订阅者列表中。
     * 如果是热流并且已经连接，消费者会立即接收到缓存中的数据。
     * 
     * @param subscriber 订阅者
     */
    public void subscribe(Consumer<T> subscriber) {
        if (completed) {
            throw new IllegalStateException("不能订阅已经完成的流。");
        }
        if (isCold) {
            subscribers.add(subscriber);
        } else {
            if (isConnected.get()) {
                for (T data : dataBuffer) {
                    subscriber.accept(data);
                }
            }
            subscribers.add(subscriber);
        }
    }

    /**
     * 发布数据方法，向所有订阅者发送数据。
     * 如果数据流已经完成，则抛出异常。
     * 如果是冷流，数据会被缓存。
     * 
     * @param data 要发布的数据
     */
    public void publish(T data) {
        if (completed) {
            throw new IllegalStateException("不能向已完成的流发布数据。");
        }
        if (isCold) {
            dataBuffer.add(data);
        }
        for (Consumer<T> subscriber : subscribers) {
            subscriber.accept(data);
        }
    }

    /**
     * 结束数据流方法，标记数据流为完成状态，并打印结束信息。
     */
    public void complete() {
        completed = true;
        System.out.println("数据流已经结束。");
    }

    /**
     * 将冷流转换为热流的方法。
     * 这个方法会立即将缓存的数据发送给所有订阅者。
     */
    public void convertToHotStream() {
        if (isCold) {
            isCold = false;
            isConnected.set(true);
            for (T data : dataBuffer) {
                for (Consumer<T> subscriber : subscribers) {
                    subscriber.accept(data);
                }
            }
            dataBuffer.clear(); // 清空缓存
        }
    }

    /**
     * 连接热流方法，开始发送缓存的数据给所有订阅者。
     * 如果数据流是冷流，则抛出异常。
     */
    public void connect() {
        if (isCold) {
            throw new IllegalStateException("Cannot connect a cold stream. Convert it to hot stream first.");
        }
        isConnected.set(true);
        for (T data : dataBuffer) {
            for (Consumer<T> subscriber : subscribers) {
                subscriber.accept(data);
            }
        }
        dataBuffer.clear(); // 清空缓存
    }

    /**
     * map 操作符，创建一个新的 FluxData 对象，对原始数据流中的每个元素应用映射函数。
     * 
     * @param mapper 映射函数
     * @param <R>    映射后的数据类型
     * @return 应用映射函数后的新数据流
     */
    public <R> FluxData<R> map(Function<T, R> mapper) {
        FluxData<R> mappedFlux = new FluxData<>();
        this.subscribe(item -> mappedFlux.publish(mapper.apply(item)));
        return mappedFlux;
    }

    /**
     * filter 操作符，创建一个新的 FluxData 对象，只传递满足条件的元素。
     * 
     * @param predicate 过滤条件
     * @return 应用过滤条件后的新数据流
     */
    public FluxData<T> filter(Predicate<T> predicate) {
        FluxData<T> filteredFlux = new FluxData<>();
        this.subscribe(item -> {
            if (predicate.test(item)) {
                filteredFlux.publish(item);
            }
        });
        return filteredFlux;
    }
}

/**
 * 测试类，包含对 FluxData 类的测试用例。
 */
public class FluxDataExample {

    public static void main(String[] args) {
        testSubscribeAndPublish();
        testCompleteStream();
        testColdToHotStream();
        testHotStreamConnect();
        testMapOperator();
        testFilterOperator();
    }

    /**
     * 测试订阅和发布数据。
     * 验证订阅者能够接收到发布到数据流中的数据。
     */
    public static void testSubscribeAndPublish() {
        FluxData<String> fluxData = new FluxData<>();
        final List<String> receivedData = new ArrayList<>();
        // 方法引用：双冒号（::）语法直接引用已有方法作为 lambda 表达式的实现。
        // 这种方式是最简洁的，当 lambda 表达体只需要调用一个方法时使用。
        // Consumer<String> subscriber = receivedData::add;

        // Lambda 表达式：使用箭头（->）语法定义 lambda 表达式。
        // 这种方式比匿名内部类简洁，但不如方法引用简洁。
        // 当 lambda 表达体较为简单，只包含一行代码时，可以使用 lambda 表达式。
        // Consumer<String> subscriber = data -> receivedData.add(data);

        // 匿名内部类：通过创建一个实现了 Consumer 接口的匿名类实例来定义 lambda 表达式的逻辑。
        // 这种方式在 lambda 表达体较为复杂，需要多行代码实现。
        // 与 lambda 表达式相比，匿名内部类提供了更多的灵活性，但代码更为冗长。
        Consumer<String> subscriber = new Consumer<String>() {
            @Override
            public void accept(String item) {
                System.out.println("accept接收到数据：" + item);
                receivedData.add(item);
            }
        };
        fluxData.subscribe(subscriber);
        fluxData.publish("Hello!");
        if (!receivedData.get(0).equals("Hello")) {
            System.out.println("测试失败：订阅和发布数据");
        } else {
            System.out.println("测试通过：订阅和发布数据。接收到：" + receivedData);
        }
    }

    /**
     * 测试结束数据流。
     * 验证数据流结束后不能再发布数据。
     */
    public static void testCompleteStream() {
        FluxData<String> fluxData = new FluxData<>();
        fluxData.complete();
        try {
            fluxData.publish("How are you?");
            System.out.println("测试失败：数据流已经结束。");
        } catch (IllegalStateException e) {
            System.out.println("测试通过：结束数据流。提示：" + e.getMessage());
        }
    }

    /**
     * 测试冷流转换为热流。
     * 验证冷流可以转换为热流。
     */
    /**
     * 测试冷流转换为热流。
     * 验证冷流可以转换为热流，并且连接后订阅者能够接收到缓存的数据。
     */
    public static void testColdToHotStream() {
        FluxData<String> fluxData = new FluxData<>();
        // 先发布数据到冷流
        fluxData.publish("Hi, Tom");
        // 创建订阅者并订阅数据流
        final List<String> receivedData = new ArrayList<>();
        Consumer<String> subscriber = receivedData::add;
        fluxData.subscribe(subscriber);

        // 将冷流转换为热流
        fluxData.convertToHotStream();

        // 验证订阅者是否接收到了之前缓存的数据
        System.out.println(receivedData);
        if (receivedData.size() > 0 && receivedData.get(0).equals("Hi, Tom")) {
            System.out.println("测试通过：冷流转换为热流并连接");
        } else {
            System.out.println("测试失败：冷流转换为热流并连接");
        }
    }

    /**
     * 测试热流连接。
     * 验证热流连接后，订阅者能够接收到缓存的数据。
     */
    public static void testHotStreamConnect() {
        FluxData<String> fluxData = new FluxData<>();
        fluxData.publish("Hi, Jerry"); // 发布数据到冷流

        final List<String> receivedData = new ArrayList<>();
        Consumer<String> subscriber = receivedData::add;
        fluxData.subscribe(subscriber); // 订阅数据流

        fluxData.convertToHotStream(); // 将冷流转换为热流

        // 验证 receivedData 是否为空
        System.out.println(receivedData);
        if (receivedData.isEmpty()) {
            System.out.println("测试失败：订阅者未接收到任何数据");
        } else if (!receivedData.get(0).equals("Hi, Jerry")) {
            System.out.println("测试失败：热流连接 - 数据不匹配");
        } else {
            System.out.println("测试通过：热流连接");
        }
    }

    /**
     * 测试 map 操作符。
     * 验证 map 操作符能够正确地对数据流中的每个元素应用映射函数。
     */
    public static void testMapOperator() {
        FluxData<Integer> fluxData = new FluxData<>();
        FluxData<String> mappedFlux = fluxData.map(Object::toString);
        final List<String> receivedData = new ArrayList<>();
        Consumer<String> subscriber = receivedData::add;
        mappedFlux.subscribe(subscriber);
        fluxData.publish(110);
        if (!receivedData.get(0).equals("110")) {
            System.out.println("测试失败：map 操作符" + receivedData);
        } else {
            System.out.println("测试通过：map 操作符" + receivedData);
        }
    }

    /**
     * 测试 filter 操作符。
     * 验证 filter 操作符能够正确地过滤数据流中的元素。
     */
    public static void testFilterOperator() {
        FluxData<Integer> fluxData = new FluxData<>();
        FluxData<Integer> filteredFlux = fluxData.filter(x -> x > 50);
        final List<Integer> receivedData = new ArrayList<>();
        Consumer<Integer> subscriber = receivedData::add;
        filteredFlux.subscribe(subscriber);
        fluxData.publish(40);
        fluxData.publish(60);
        if (receivedData.get(0) != 60) {
            System.out.println("测试失败：filter 操作符" + receivedData);
        } else {
            System.out.println("测试通过：filter 操作符" + receivedData);
        }
    }
}