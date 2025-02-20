// 应用服务层（Application Layer） - order_service.c
#include "../service/order_service.h"
#include "../repository/order_repository.h"
#include <stdio.h>

// 创建订单
void createOrderService(int id, const char *customerName, double amount)
{
    Order *order = createOrder(id, customerName, amount);
    if (order)
    {
        saveOrder(order);
        printf("订单 ID %d 创建成功\n", id);
    }
}

// 取消订单
void cancelOrderService(int id)
{
    Order *order = getOrderById(id);
    if (order)
    {
        cancelOrder(order);
    }
    else
    {
        printf("未找到 ID %d\n", id);
    }
}

// 查询订单
void queryOrderService(int id)
{
    Order *order = getOrderById(id);
    if (order)
    {
        displayOrderInfo(order);
    }
    else
    {
        printf("未找到 ID %d\n", id);
    }
}
