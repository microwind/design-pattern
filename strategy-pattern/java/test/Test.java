package test;

import src.*;

public class Test {

  public static void start() {
  /**
   * 策略模式就是根据需要给对象绑定具体策略，使得具体实现和策略可以灵活搭配。
   * 先声明某个具体Context对象，该对象已经绑定了具体策略，同时还可以更改策略。
   */

    // 实例化某个内容，策略已经绑定上
    Context contextCat = new ContextCat();
    contextCat.action();

    // 重新设置策略
    System.out.println("reset contextCat'strategy to StrategyA.");
    contextCat.setStrategy(new StrategyA());
    contextCat.action();
    
    // 实例化某个内容，策略已经绑定上
    Context contextGog = new ContextDog();
    contextGog.action();

  }
  public static void main(String[] args) {
    System.out.println("test start:");
    start();
  }

}

/**
 * 测试
jarry@jarrys-MacBook-Pro java % javac test/Test.java
jarry@jarrys-MacBook-Pro java % java test/Test      
test start:
ContextCat::setStrategy(StrategyC).
StrategyC::run().
reset contextCat'strategy to StrategyA.
StrategyA::run().
ContextDog::setStrategy(StrategyB).
StrategyB::run().
 */