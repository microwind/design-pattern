package test;

import java.util.Map;

import src.*;

public class Test {

  public static void start() {
  /**
   * 享元模式就是将已经声明过的实例或数据保存在内存里，需要使用时则取出来，无需再次实例化和声明。
   * 通过共享多个对象所共有的相同状态，以达到节省开销的目的。
   */

    // 假设有钢琴和吉他，钢琴使用者很多需要共享实例，而吉他每次创建新实例

    // 2个一样名称的共享对象
    Flyweight factory1 = FlyweightFactory.getFactory("piano1");
    // piano1已经声明过了，同名则共享前面的实例
    Flyweight factory2 = FlyweightFactory.getFactory("piano1");
    Flyweight factory3 = FlyweightFactory.getFactory("piano2");

    factory1.operate("factory1");
    factory2.operate("factory2");
    factory3.operate("factory3");

    // 查看一共多少个对象
    for (Map.Entry<String, Flyweight> entry : FlyweightFactory.pool.entrySet()) {
      System.out.println("保存的对象:" + entry.getKey());
      // entry.getValue().operate(null);
    }

    // 无需共享的，名字一样也是多个对象
    Flyweight factory4 = new UnsharedConcreteFlyweight("guitar1");
    Flyweight factory5 = new UnsharedConcreteFlyweight("guitar1");
    factory4.operate("factory4");
    factory5.operate("factory5");

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
 * src.ConcreteFlyweight::operate() [piano1 piano factory1]
 * src.ConcreteFlyweight::operate() [piano1 piano factory2]
 * src.ConcreteFlyweight::operate() [piano2 piano factory3]
 * 保存的对象:piano1
 * 保存的对象:piano2
 * src.UnsharedConcreteFlyweight::operate() [guitar1 guitar factory4]
 * src.UnsharedConcreteFlyweight::operate() [guitar1 guitar factory5]
 */