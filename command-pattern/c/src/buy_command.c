#include "func.h"

// 购买命令，操作receiver，实现了抽象命令类

void set_buy_stock_receiver(BuyCommand *command, StockReceiver *receiver)
{
  command->stock_receiver = receiver;
}

// 命令类调用执行者来自行真正的动作
void buy_command_execute(Command *command)
{
  printf("\r\n BuyCommand::execute() [command->name=%s]", command->name);
  command->stock_receiver->buy(command->stock_receiver);
}

// 创建Buy命令对象
BuyCommand *buy_command_constructor(char *name)
{
  Command *command = (Command *)malloc(sizeof(Command));
  strncpy(command->name, name, 50);
  command->execute = &buy_command_execute;
  // 转为BuyCommand
  BuyCommand *buy_command = (BuyCommand *)command;
  buy_command->set_stock_receiver = &set_buy_stock_receiver;
  return buy_command;
}