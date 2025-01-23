import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

// 自定义 Flux 数据流
class SimpleFlux<T> {

  public SimpleFlux() {
    System.out.println("数据流创建成功。");
  }

  // 存储订阅者
  private final List<Consumer<T>> subscribers = new ArrayList<>();
  private boolean completed = false;

  // 订阅方法
  public void subscribe(Consumer<T> subscriber) {
    if (completed) {
      throw new IllegalStateException("不能订阅已经完成的流。");
    }
    subscribers.add(subscriber);
  }

  // 发布数据
  public void publish(T data) {
    if (completed) {
      throw new IllegalStateException("不能向已完成的流发布数据。");
    }
    for (Consumer<T> subscriber : subscribers) {
      subscriber.accept(data);
    }
  }

  // 结束数据流
  public void complete() {
    completed = true;
    System.out.println("数据流已经结束。");
  }

}

public class SimpleFluxExample {

  public static void main(String[] args) {
    // 创建一个自定义的 Flux 数据流
    SimpleFlux<String> flux = new SimpleFlux<>();

    // 添加订阅者，打印流数据
    flux.subscribe(data -> System.out.println("订阅者 A 收到: " + data));
    flux.subscribe(data -> System.out.println("订阅者 B 收到: " + data));

    // 发布数据
    flux.publish("消息1");
    flux.publish("消息2");
    flux.publish("消息3");

    // 结束流
    flux.complete();
    flux.subscribe(data -> System.out.println("订阅者 C 收到: " + data));

    /************ 分割线 ********************/
    // 创建一个自定义的 Flux 数据流
    SimpleFlux<Integer> flux2 = new SimpleFlux<>();

    // 添加订阅者，打印流数据
    flux2.subscribe(data -> System.out.println("订阅者 A 收到: " + data));
    flux2.subscribe(data -> System.out.println("订阅者 B 收到: " + data));

    // 发布数据
    flux2.publish(1);
    flux2.publish(2);
    flux2.publish(3);

    // 结束流
    flux2.complete();
  }
}
/**
 * 打印结果
 * jarry@MacBook-Pro flux % javac SimpleFluxExample.java
 * jarry@MacBook-Pro flux % java SimpleFluxExample
 * 数据流创建成功。
 * 订阅者 A 收到: 消息1
 * 订阅者 B 收到: 消息1
 * 订阅者 A 收到: 消息2
 * 订阅者 B 收到: 消息2
 * 订阅者 A 收到: 消息3
 * 订阅者 B 收到: 消息3
 * 数据流已经结束。
 * Exception in thread "main" java.lang.IllegalStateException: 不能订阅已经完成的流。
 * at SimpleFlux.subscribe(SimpleFluxExample.java:19)
 * at SimpleFluxExample.main(SimpleFluxExample.java:59)
 */