package test;

import src.*;

public class Test {

  public static void start() {

    /**
     * 状态模式就是不同的状态下有不同的行为，当前对象只有一种状态
     * 策略模式可以重新设置策略，状态则通过动作来切换
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