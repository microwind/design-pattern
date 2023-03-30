#include "func.h"

// 出售命令，操作receiver，实现了抽象命令类

void set_sell_stock_receiver(SellCommand *command, StockReceiver *receiver) {
  command->stock_receiver = receiver;
}

// 命令类调用执行者来自行真正的动作
void sell_command_execute(Command *command) {
  printf("\r\n SellCommand::execute() [command->name=%s]", command->name);
  command->stock_receiver->sell(command->stock_receiver);
}

// 创建Sell命令对象
SellCommand *sell_command_constructor(char *name)
{
  Command *command = (Command *)malloc(sizeof(Command));
  strncpy(command->name, name, 50);
  command->execute = &sell_command_execute;
  // 转为SellCommand
  SellCommand *buy_command = (SellCommand *)command;
  buy_command->set_stock_receiver = &set_sell_stock_receiver;
  return buy_command;
}