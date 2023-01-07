package test;

import src.*;

public class Test {

  public static void start() {
    /*
     * 备忘录模式是在不暴露对象实现细节的情况下保存和恢复对象之前的状态。
     * 先声明发起人Originator，再声明负责人Caretaker，发起人生成备忘录Memento
     * 通过负责人则保存备忘录历史记录，读取备忘录由负责人来完成。
     */
    Originator originator = new Originator();
    Caretaker careTaker = new Caretaker();
    // 发起人产生一个状态
    originator.setState("state1");
    // 覆盖了状态，那么前面的状态未保存
    originator.setState("state2");
    // 发起人生成备忘录，一般添加时直接保存即可
    Memento memento = originator.saveMemento();
    // 负责人保添加备忘录历史记录
    careTaker.add(memento);

    // 直接生成备忘录并添加到负责人的备忘录列表
    originator.setState("state3");
    careTaker.add(originator.saveMemento());
    originator.setState("state4");
    careTaker.add(originator.saveMemento());

    System.out.println("发起人当前的状态: " + originator.getState());

    // 发起人通过负责人那里取出状态
    originator.restoreMemento(careTaker.get(0));
    System.out.println("第一个保存的状态: " + originator.getState());
    originator.restoreMemento(careTaker.get(1));
    System.out.println("第二个保存的状态: " + originator.getState());

    // 遍历全部备忘录
    for (int i = 0; i < careTaker.getMementoList().size(); i++) {
      // 外部一般不直接访问备忘录里面的状态，而是逐个恢复备忘录，再取出状态来
      originator.restoreMemento(careTaker.get(i));
      System.out.println("state: " + i + ")" + originator.getState());
    }
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
 * src.ObjectList::createIterator() [获取迭代器 ObjectIterator]
 * objectList[0] = Thomas
 * objectList[1] = Merry
 * objectList[2] = Jack
 * objectList[3] = Tony
 * objectList[4] = Jerry
 * objectList[5] = Joey
 * src.ObjectList::createIterator() [获取迭代器 ObjectIterator]
 * Thomas
 * Merry
 * Jack
 * Tony
 * Jerry
 * Joey
 */