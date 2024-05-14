package src;

/**
 * Order数据库访问类，负责处理订单的CRUD操作
 */
public class OrderDao {

    // 删除订单
    protected boolean deleteOrder(Long orderId) {
        // doSomething
        return true;
    }

    // 保存订单到数据库
    protected boolean saveOrder(Long orderId) {
        if (orderId % 2 == 0) {
            System.out.println("data saving.");
        }
        System.out.println("data save done.");
        return true;
    }

}