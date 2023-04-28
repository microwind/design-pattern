#include "func.h"

// 具体的元素实现者B

void concrete_element_b_bccept(ConcreteElementB *ele, Visitor *visitor)
{
  printf("\r\n ConcreteElementB::accept() [Visitor.name = %s]", visitor->name);
  visitor->visit_b(ele);
}

void concrete_element_b_operate(ConcreteElementB *ele)
{
  printf("\r\n ConcreteElementB::operate() [%s]", ele->name);
}

ConcreteElementB *concrete_element_b_constructor()
{
  // printf("\r\n concrete_element_b_constructor() [构建ConcreteElementB]");
  Element *ele = (Element *)malloc(sizeof(Element));
  ConcreteElementB *ele_b = (ConcreteElementB *)ele;
  strcpy(ele_b->name, "Keyboard Element(struct=ConcreteElementB)");
  ele_b->accept = &concrete_element_b_bccept;
  ele_b->operate = &concrete_element_b_operate;
  return ele_b;
}
