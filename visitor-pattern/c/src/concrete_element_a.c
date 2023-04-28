#include "func.h"

// 具体的元素实现者A

void concrete_element_a_accept(ConcreteElementA *ele, Visitor *visitor)
{
  printf("\r\n ConcreteElementA::accept() [Visitor.name = %s]", visitor->name);
  visitor->visit_a(ele);
}

void concrete_element_a_operate(ConcreteElementA *ele)
{
  printf("\r\n ConcreteElementA::operate() [%s]", ele->name);
}

ConcreteElementA *concrete_element_a_constructor()
{
  // printf("\r\n concrete_element_a_constructor() [构建ConcreteElementA]");
  Element *ele = (Element *)malloc(sizeof(Element));
  ConcreteElementA *ele_a = (ConcreteElementA *)ele;
  strcpy(ele_a->name, "Monitor Element(struct=ConcreteElementA)");
  ele_a->accept = &concrete_element_a_accept;
  ele_a->operate = &concrete_element_a_operate;
  return ele_a;
}
