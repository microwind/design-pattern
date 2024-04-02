package src;

/**
 * 这个例子违反了单一职责原则。
 * 1. 订单处理类实现了订单校验以及保存数据库的两种逻辑。
 * 2. 一旦订单条件有修改或保存数据库方式有变更都需要改动此类。
 */
public class SingleResponsibility_counter {
    public SingleResponsibility_counter() {
        return;
    }

    // 订单处理逻辑
    public Object processOrder(Long orderId) {
        System.out.println("order ID: " + orderId);
        // 1. 先验证订单
        if (!this.validateOrder(orderId)) {
            System.out.println("order validate failed.");
            return false;
        }

        // 2. 将订单数据逻辑处理
        if (orderId % 2 == 0) {
            System.out.println("order data processing.");
        }

        // 3. 再保存订单到数据库
        System.out.println("order info save to DB.");
        this.saveOrderToDatabase(orderId);

        return true;
    }

    // 校验订单逻辑，最好别放在订单处理类中
    private boolean validateOrder(Long orderId) {
        // doSomething
        if (orderId % 2 == 1) {
            return false;
        }
        return true;
    }

    // 保存订单到数据库逻辑，不应该放在订单处理类中
    private boolean saveOrderToDatabase(Long orderId) {
        if (orderId % 2 == 0) {
            System.out.println("order saving.");
        }
        System.out.println("order save done.");
        return true;
    }
}