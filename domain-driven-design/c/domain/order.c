// 领域层（Domain Layer） - order.c
#include "order.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 创建订单
Order *createOrder(int id, const char *customerName, double amount)
{
    if (amount < 0)
    {
        printf("订单金额不能为负数\n");
        return NULL;
    }

    Order *order = (Order *)malloc(sizeof(Order));
    if (!order)
    {
        printf("内存分配失败\n");
        return NULL;
    }

    order->id = id;
    strncpy(order->customerName, customerName, MAX_NAME_LENGTH - 1);
    order->customerName[MAX_NAME_LENGTH - 1] = '\0'; // 确保字符串以 '\0' 结尾
    order->amount = amount;
    order->status = CREATED; // 订单默认状态

    return order;
}

// 取消订单
void cancelOrder(Order *order)
{
    if (!order)
    {
        printf("订单不存在\n");
        return;
    }

    if (order->status == CREATED)
    {
        order->status = CANCELED;
        printf("订单 ID %d 已取消\n", order->id);
    }
    else
    {
        printf("订单 ID %d 已经取消，无法重复操作\n", order->id);
    }
}

// 释放订单
void freeOrder(Order *order)
{
    if (order)
    {
        free(order);
    }
}

// 显示订单信息
void displayOrderInfo(const Order *order)
{
    if (!order)
    {
        printf("无效订单\n");
        return;
    }

    printf("订单 ID: %d\n", order->id);
    printf("客户名称: %s\n", order->customerName);
    printf("订单金额: %.2f\n", order->amount);
    printf("订单状态: %s\n", order->status == CREATED ? "已创建" : "已取消");
}
