package test;

import src.*;

public class Test {

  public static void start() {
    /**
     * 单例模式就是一个类只创建一个实例，以便节省开销和保证统一
     * 对于多线程语言需要注意线程安全和性能之间取得一个平衡
     */
    SingletonEager singletonEager1 = SingletonEager.getInstance();
    SingletonEager singletonEager2 = SingletonEager.getInstance();
    singletonEager1.run();
    singletonEager2.run();
    // 两个实例相等
    System.out.println("singletonEager1 == singletonEager2 ? " + String.valueOf(singletonEager1 == singletonEager2));

    /*********************** 分割线 ******************************************/

    SingletonLazy singletonLazy1 = SingletonLazy.getInstance("singletonLazy1");
    SingletonLazy singletonLazy2 = SingletonLazy.getInstance("singletonLazy2");
    singletonLazy1.run();
    singletonLazy2.run();

    /*********************** 分割线 ******************************************/

    SingletonDoubleCheck singletonDoubleCheck1 = SingletonDoubleCheck.getInstance("singletonDoubleCheck1");
    SingletonDoubleCheck singletonDoubleCheck2 = SingletonDoubleCheck.getInstance("singletonDoubleCheck2");
    singletonDoubleCheck1.run();
    singletonDoubleCheck2.run();

    /*********************** 分割线 ******************************************/

    SingletonInner singletonInner1 = SingletonInner.getInstance("singletonInner1");
    SingletonInner singletonInner2 = SingletonInner.getInstance("singletonInner2");
    singletonInner1.run();
    singletonInner2.run();
  }

  public static void main(String[] args) {
    System.out.println("test start:");
    start();
  }

}

/**
 * 测试
 * jarry@jarrys-MacBook-Pro java % java --version
 * java 14.0.1 2020-04-14
 * Java(TM) SE Runtime Environment (build 14.0.1+7)
 * Java HotSpot(TM) 64-Bit Server VM (build 14.0.1+7, mixed mode, sharing)
 * 
 * jarry@jarrys-MacBook-Pro java % javac test/Test.java
 * jarry@jarrys-MacBook-Pro java % java test/Test
 * test start:
 * SingletonEager::run() SingletonEager
 * SingletonEager::run() SingletonEager
 * singletonEager1 == singletonEager2 ? true
 * SingletonLazy::run() singletonLazy1
 * SingletonLazy::run() singletonLazy1
 * SingletonDoubleCheck::run() singletonDoubleCheck1
 * SingletonDoubleCheck::run() singletonDoubleCheck1
 * SingletonInner::run() singletonInner1
 * SingletonInner::run() singletonInner1
 */