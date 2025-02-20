#ifndef ORDER_REPOSITORY_H
#define ORDER_REPOSITORY_H

#include "../domain/order.h"

void saveOrder(Order *order);
Order *getOrderById(int id);
void viewOrderHistory();
void clearOrders(); // 释放所有订单

#endif
