package test;

import src.*;

public class Test {

  public static void start() {

    /*
     * 解释器模式先构建执行上下文，然后构建表达式，再传入变量，然后进行解释计算。
     */
    int result1 = Application.addTwo(1, 2);
    System.out.println("result1:" + result1);

    int result2 = Application.addMore(1, 2, 3, 4, 5);
    System.out.println("result2:" + result2);

    int result3 = Application.addAndSubtract(3, 4, 5);
    System.out.println("result3:" + result3);
   
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
