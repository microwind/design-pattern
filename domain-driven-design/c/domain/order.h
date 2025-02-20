#ifndef ORDER_H
#define ORDER_H

#define MAX_NAME_LENGTH 100

// 订单状态枚举
typedef enum
{
    CREATED,
    CANCELED
} OrderStatus;

// 订单结构体
typedef struct
{
    int id;
    char customerName[MAX_NAME_LENGTH];
    double amount;
    OrderStatus status;
} Order;

// 订单操作函数
Order *createOrder(int id, const char *customerName, double amount);
void cancelOrder(Order *order);
void freeOrder(Order *order);
void displayOrderInfo(const Order *order);

#endif
