package test;

import src.*;

public class Test {

  public static void start() {
  /**
   * 访问者模式是当客户需要访问具体各元素Element时，先建立一个访问者Visitor作为媒介
   * 客户基于对象结构ObjectStructure，调用accept()，接受传入的访问者
   * 对象结构向其他元素负责分发访问者，元素对象接受之后会将自己回传给访问者，从而访问者可以访问具体元素
   */
    ObjectStructure structure = new ObjectStructure();
    // 接受访问者A，把访问者传递给具体元素
    structure.accept(new ConcreteVisitorA());

    System.out.println("====");
    // 接受访问者B，把访问者传递给具体元素
    structure.accept(new ConcreteVisitorB());

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
ObjectStructure::accept() [visitor.class = ConcreteVisitorA visitor.name = Google Visitor]
ConcreteElementA::accept() [visitor.class = ConcreteVisitorA visitor.name = Google Visitor]
ConcreteVisitorA::visit() [Element.class = ConcreteElementA Element.name = Monitor Element]
ConcreteElementA::operate() [Monitor Element]
ConcreteElementB::accept() [visitor.class = ConcreteVisitorA visitor.name = Google Visitor]
ConcreteVisitorA::visit() [Element.class = ConcreteElementB Element.name = Keyboard Element]
ConcreteElementB::operate() [Keyboard Element]
====
ObjectStructure::accept() [visitor.class = ConcreteVisitorB visitor.name = Apple Visitor]
ConcreteElementA::accept() [visitor.class = ConcreteVisitorB visitor.name = Apple Visitor]
ConcreteVisitorB::visit() [Element.class = ConcreteElementA Element.name = Monitor Element]
ConcreteElementA::operate() [Monitor Element]
ConcreteElementB::accept() [visitor.class = ConcreteVisitorB visitor.name = Apple Visitor]
ConcreteVisitorB::visit() [Element.class = ConcreteElementB Element.name = Keyboard Element]
ConcreteElementB::operate() [Keyboard Element]
 */