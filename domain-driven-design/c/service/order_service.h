#ifndef ORDER_SERVICE_H
#define ORDER_SERVICE_H

void createOrderService(int id, const char *customerName, double amount);
void cancelOrderService(int id);
void queryOrderService(int id);

#endif
