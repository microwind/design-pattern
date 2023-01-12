package test;

import src.*;

public class Test {

  public static void start() {
    /*
     * 迭代器模式是给数据容器创建单独的迭代器，用来遍历里面的数据对象
     * 数据容器和迭代器相互关联，外部通过迭代器来访问数据容器
     * 通过这种方式由迭代器类来负责数据遍历，这样可以做到不暴露集合的内部结构
     */

    int i = 0;
    ObjectList objectList = new ObjectList();
    objectList.setObjects(new String[] { "Thomas", "Merry", "Jack", "Tony", "Jerry", "Joey" });
    // for循环迭代对象
    for (Iterator iter = objectList.createIterator(); iter.hasNext();) {
      String name = (String) iter.next();
      System.out.println("objectList[" + i + "] = " + name);
      i++;
    }

    // while循环迭代对象
    Iterator iter2 = objectList.createIterator();
    while (iter2.hasNext()) {
      System.out.println(iter2.next());
    }

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