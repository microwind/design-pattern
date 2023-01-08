package test;

import src.*;

public class Test {

  public static void start() {

    /**
     * 观察者模式应用非常广泛，主要是观察者提前绑定到发布者
     * 当发布者发布消息时，批量广播通知，而无需逐一通知
     * 观察者监听到消息后自己决定采取哪一种行为
     */

    // 定义一个主题，也就是发布者
    Subject concreteSubject = new ConcreteSubject("subject1");
    // 再声明观察者，通过构造器注册到主题上
    ObserverAPI observer1 = new ConcreteObserver(concreteSubject);

    // 也可以单独给主题注册一个新的观察者
    concreteSubject.register(new ConcreteObserver2());
    // 可以移除观察者对象
    // concreteSubject.remove(observer1);

    // 主题开始发布新通知，各观察者自动更新
    concreteSubject.notify("hello, this is broadcast.");

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
 * ConcreteSubject::register() [observer = ConcreteObserver]
 * ConcreteSubject::register() [observer = ConcreteObserver2]
 * ConcreteSubject::notify() [content = hello, this is broadcast.]
 * ConcreteObserver::update() [subject.name = subject1 content = hello, this is
 * broadcast.]
 * ConcreteObserver2::update() [content = hello, this is broadcast.]
 */