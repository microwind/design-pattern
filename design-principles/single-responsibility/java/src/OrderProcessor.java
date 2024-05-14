package src;

/**
 * 这个例子符合单一职责原则。
 * 1.
 * 分别建立三个类，一个负责订单业务处理(OrderProcessor)，一个负责校验订单(OrderValidator)，一个负责保存数据(OrderDao)，各司其职。
 * 2. 由处理订单来负责调用工具类，订单业务逻辑修改不会影响到工具类。
 * 3. 工具类修改也不会影响到订单业务处理。
 * 4. 职责是否足够单一，要根据具体场景而异，不同情形下采用不同的设计，主要的目标是便于理解、扩展和维护。
 */
public class OrderProcessor {
    private OrderValidator orderValidator = new OrderValidator();
    private OrderDao orderDao = new OrderDao();

    public OrderProcessor() {
        return;
    }

    // 订单处理逻辑方法
    public Object processOrder(Long orderId) {
        System.out.println("oder ID：" + orderId);
        // 1. 先验证订单，调用校验类
        if (!orderValidator.validateId(orderId)) {
            System.out.println("order validate id failed.");
            return false;
        }

        if (!orderValidator.validateTime(System.currentTimeMillis())) {
            System.out.println("order validate time failed.");
            return false;
        }

        // 2. 订单数据其他逻辑处理
        if (orderId % 2 == 0) {
            System.out.println("order data processing.");
        }

        // 3. 再保存订单到数据库，调用数据库类
        System.out.println("order save to DB.");
        orderDao.saveOrder(orderId);
        // 或则删除订单
        // orderDao.deleteOrder(orderId);

        return true;
    }
}