package test;

import src.*;

public class Test {

  public static void start() {

    /*
     * 命令模式是客户端通过一个命令执行者invoker，去执行某个命令command
     * 而命令则调用了业务类receiver的具体动作，从而完成真正的执行
     */

    // 先声明一个被操作对象，也就是接收者
    StockReceiver stock1 = new StockReceiver("Apple", 200);

    // 再声明具体的命令
    BuyCommand buyCommand = new BuyCommand(stock1);
    SellCommand sellCommand = new SellCommand(stock1);

    // 最后声明调用者，由调用者来执行具体命令
    CommandInvoker invoker = new CommandInvoker();
    invoker.takeOrder(buyCommand);
    invoker.takeOrder(sellCommand);
    invoker.executeOrders();

    // 再执行一只股票
    StockReceiver stock2 = new StockReceiver("Google", 100);
    BuyCommand buyCommand2 = new BuyCommand(stock2);
    invoker.takeOrder(buyCommand2);
    invoker.executeOrders();

  }

  public static void main(String[] args) {
    System.out.println("test start:");
    start();
  }
}
/**
 * 测试
 * jarry@jarrys-MacBook-Pro java % javac test/Test.java
 * jarry@jarrys-MacBook-Pro java % java test/Test
 * test start:
 * src.CommandInvoker::takeOrder() src.BuyCommand
 * src.CommandInvoker::takeOrder() src.SellCommand
 * src.CommandInvoker::executeOrders()
 * src.BuyCommand::execute()
 * src.StockReceiver::buy() [name=Apple num=200]
 * src.SellCommand::execute()
 * src.StockReceiver::sell() [name=Apple num=200]
 * src.CommandInvoker::takeOrder() src.BuyCommand
 * src.CommandInvoker::executeOrders()
 * src.BuyCommand::execute()
 * src.StockReceiver::buy() [name=Google num=100]
 */
