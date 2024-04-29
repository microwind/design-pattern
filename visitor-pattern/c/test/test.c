#include "../src/func.h"

int main(void)
{
  printf("test start:\r\n");
  /**
   * 访问者模式是当客户需要访问具体各元素Element时，先建立一个访问者Visitor作为媒介
   * 客户基于对象结构ObjectStructure，调用Accept()，接受传入的访问者
   * 对象结构向其他元素负责分发访问者，元素对象接受之后会将自己回传给访问者，从而访问者可以访问具体元素
   */
  ObjectStructure *structure = object_structure_constructor();
  // 接受访问者A，把访问者传递给具体元素
  structure->accept(structure, (Visitor *)concrete_visitor_a_constructor());

  printf("\r\n ====");
  // 接受访问者B，把访问者传递给具体元素
  structure->accept(structure, (Visitor *)concrete_visitor_b_constructor());
}

// jarry@jarrys-MacBook-Pro c % gcc test/test.c ./src/*.c
// jarry@jarrys-MacBook-Pro c % ./a.out
/**
test start:

 object_structure_constructor() [构建ObjectStructure]
 ObjectStructure::accept() [Visitor.name = Google Visitor(struct=ConcreteVisitorA)]
 ConcreteElementA::accept() [Visitor.name = Google Visitor(struct=ConcreteVisitorA)]
 ConcreteVisitorA::visit_a() [Element.name = Monitor Element(struct=ConcreteElementA)]
 ConcreteElementA::operate() [Monitor Element(struct=ConcreteElementA)]
 ConcreteElementB::accept() [Visitor.name = Google Visitor(struct=ConcreteVisitorA)]
 ConcreteVisitorA::visit_b() [Element.name = Keyboard Element(struct=ConcreteElementB)]
 ConcreteElementB::operate() [Keyboard Element(struct=ConcreteElementB)]
 ====
 ObjectStructure::accept() [Visitor.name = Apple Visitor(struct=ConcreteVisitorB)]
 ConcreteElementA::accept() [Visitor.name = Apple Visitor(struct=ConcreteVisitorB)]
 ConcreteVisitorB::visit_a() [Element.name = Monitor Element(struct=ConcreteElementA)]
 ConcreteElementA::operate() [Monitor Element(struct=ConcreteElementA)]
 ConcreteElementB::accept() [Visitor.name = Apple Visitor(struct=ConcreteVisitorB)]
 ConcreteVisitorB::visit_b() [Element.name = Keyboard Element(struct=ConcreteElementB)]
 ConcreteElementB::operate() [Keyboard Element(struct=ConcreteElementB)]%
 */