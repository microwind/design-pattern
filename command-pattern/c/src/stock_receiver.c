#include "func.h"

/* 命令模式真正的执行类，不直接对外，通过command来调用 */

void stock_receiver_buy(StockReceiver *stock_receiver) {
  printf("\r\n StockReceiver::buy() [name=%s num=%d]", stock_receiver->name, stock_receiver->num);
}

void stock_receiver_sell(StockReceiver *stock_receiver) {
  printf("\r\n StockReceiver::sell() [name=%s num=%d]", stock_receiver->name, stock_receiver->num);
}

// 创建StockReceiver命令对象
StockReceiver *stock_receiver_constructor(char *name, int num)
{
  printf("\r\n stock_receiver_constructor() [name=%s, num=%d]", name, num);
  StockReceiver *receiver = (StockReceiver *)malloc(sizeof(StockReceiver));
  strncpy(receiver->name, name, 50);
  receiver->num = num;
  receiver->buy = &stock_receiver_buy;
  receiver->sell = &stock_receiver_sell;
  return receiver;
}