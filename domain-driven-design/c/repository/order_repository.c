// 基础设施层（Infrastructure Layer） - order_repository.c
#include "order_repository.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_ORDERS 100

static Order *orderStorage[MAX_ORDERS];
static int orderCount = 0;

// 保存订单
void saveOrder(Order *order)
{
    if (orderCount < MAX_ORDERS)
    {
        orderStorage[orderCount++] = order;
    }
    else
    {
        printf("存储已满，无法保存订单\n");
    }
}

// 根据 ID 获取订单
Order *getOrderById(int id)
{
    for (int i = 0; i < orderCount; i++)
    {
        if (orderStorage[i] && orderStorage[i]->id == id)
        {
            return orderStorage[i];
        }
    }
    return NULL;
}

// 查看订单历史
void viewOrderHistory()
{
    if (orderCount == 0)
    {
        printf("暂无订单历史记录。\n");
        return;
    }

    for (int i = 0; i < orderCount; i++)
    {
        displayOrderInfo(orderStorage[i]);
        printf("\n");
    }
}

// 释放所有订单
void clearOrders()
{
    for (int i = 0; i < orderCount; i++)
    {
        freeOrder(orderStorage[i]);
        orderStorage[i] = NULL;
    }
    orderCount = 0;
}
