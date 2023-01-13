package test;

import src.*;

public class Test {

  public static void start() {

    /**
     * 状态模式就是对象Context在不同行为下有不同的状态，当前只有一种状态。
     * 通过行为的改变，状态也随之自动发生了改变。
     * 策略模式与状态模式类似，但策略模式是可以重新设置策略，而状态则通过行为来切换状态。
     */

    Context context = new Context();
    // 初始状态是off
    context.setState(new ConcreteStateOff());
    // turn on
    context.turnOn();
    // 再次turn on
    context.turnOn();
    // turn off
    context.turnOff();
    // 再次turn off
    context.turnOff();
    System.out.println("context.state: " + context.getState().getClass().getSimpleName());
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
 * Context::setState() [state = ConcreteStateOff]
 * ConcreteStateOff::on() [turn ON ok!]
 * Context::setState() [state = ConcreteStateOn]
 * ConcreteStateOn::on() [needn't switch, state is ON.]
 * ConcreteStateOn::off() [turn OFF ok!]
 * Context::setState() [state = ConcreteStateOff]
 * ConcreteStateOff::off() [needn't switch, state is OFF.]
 * context.state: ConcreteStateOff
 */