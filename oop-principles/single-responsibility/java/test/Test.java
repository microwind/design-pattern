package test;

import src.*;

public class Test {

  public static void start() {

    /**
     * 测试不符合单一职责的例子
     */
    SingleResponsibility_counter orderProcessorCounter = new SingleResponsibility_counter();
    orderProcessorCounter.processOrder(1001L);
    orderProcessorCounter.processOrder(1002L);

    // *********************** 分割线 ******************************************/
    System.out.println("***********************");
    /**
     * 测试符合单一职责的例子
     */
    OrderProcessor orderProcessor = new OrderProcessor();
    orderProcessor.processOrder(1001L);
    orderProcessor.processOrder(1002L);
  }

  public static void main(String[] args) {
    System.out.println("test start:");
    start();
  }

}

/**
 * 测试
 * jarry@jarrys-MacBook-Pro java % javac -encoding utf-8 test/Test.java
 * jarry@jarrys-MacBook-Pro java % java test/Test
 * test start:
 * order ID: 1001
 * order validate failed.
 * order ID: 1002
 * order data processing.
 * order info save to DB.
 * order saving.
 * order save done.
 ***********************
 * oder ID：1001
 * order validate failed.
 * oder ID：1002
 * order data processing.
 * order save to DB.
 * data saving.
 * data save done.
 */