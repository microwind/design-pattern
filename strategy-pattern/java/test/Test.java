package test;

import src.*;

public class Test {

  public static void start() {

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