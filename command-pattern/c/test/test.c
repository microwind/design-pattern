#include "../src/func.h"

int main(void)
{
    printf("test start:\r\n");
    /*
     * 命令模式是一种行为设计模式，它将请求或操作封装成单个对象，并使其可以被参数化和延迟执行。
     * 在命令模式中，客户端通过一个命令执行者invoker，去执行某个命令command
     * 而命令则调用了业务类receiver的具体动作，从而完成真正的执行
     * 这种方式将命令和执行者进行了有效解耦。
     */

    // 先声明一个被操作对象，也就是接收者
    StockReceiver *stocker_receiver1 = stock_receiver_constructor("Apple", 200);

    // 再声明具体的命令
    BuyCommand *buy_command = buy_command_constructor("buy_command");
    buy_command->set_stock_receiver(buy_command, stocker_receiver1);

    SellCommand *sell_command = sell_command_constructor("sell_command");
    sell_command->set_stock_receiver(sell_command, stocker_receiver1);

    // 最后声明调用者，由调用者来执行具体命令
    CommandInvoker *invoker = command_invoker_constructor("invoker");
    invoker->take_order(invoker, (Command *)buy_command);
    invoker->take_order(invoker, (Command *)sell_command);
    invoker->execute_orders(invoker);

    // 再执行一只股票，声明新的接受者
    StockReceiver *stock_receiver2 = stock_receiver_constructor("Google", 100);
    BuyCommand *buy_command2 = buy_command_constructor("buy_command2");
    // 这次只有buy命令
    buy_command2->set_stock_receiver(buy_command2, stock_receiver2);
    // 还用原来的invoker，或者新建invoker
    invoker->take_order(invoker, (Command *)buy_command2);
    invoker->execute_orders(invoker);

    free(stocker_receiver1);
    free(buy_command);
    free(invoker);
    free(stock_receiver2);
    free(buy_command2);

    return 0;
}

// jarry@jarrys-MacBook-Pro c % gcc src/*.c test/test.c 
// jarry@jarrys-MacBook-Pro c % ./a.out
/**
test start:
CommandInvoker::TakeOrder() buyCommand
CommandInvoker::TakeOrder() sellCommand
CommandInvoker::ExecuteOrders()
BuyCommand::Execute()
StockReceiver::Buy() [Name=Apple Num=200]
SellCommand::Execute()
StockReceiver::Sell() [Name=Apple Num=200]
CommandInvoker::TakeOrder() buyCommand2
CommandInvoker::ExecuteOrders()
BuyCommand::Execute()
StockReceiver::Buy() [Name=Google Num=100]
 */