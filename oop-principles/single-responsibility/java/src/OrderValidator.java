package src;

/**
 * 订单校验类，校验订单的合法性和有效性等
 */
public class OrderValidator {

    // 校验订单逻辑，最好别放在订单处理类中
    public boolean validateId(Long orderId) {
        // doSomething
        if (orderId % 2 == 1) {
            return false;
        }
        return true;
    }

    public boolean validateTime(Long time) {
        // doSomething
        return false;
    }
}