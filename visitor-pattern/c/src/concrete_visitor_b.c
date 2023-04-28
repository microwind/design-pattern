#include "func.h"

// 具体访问者B

void concrete_visitor_b_visit_a(ConcreteElementA *ele)
{
  printf("\r\n ConcreteVisitorB::visit_a() [Element.name = %s]", ele->name);
  ele->operate(ele);
}

void concrete_visitor_b_visit_b(ConcreteElementB *ele)
{
  printf("\r\n ConcreteVisitorB::visit_b() [Element.name = %s]", ele->name);
  ele->operate(ele);
}

ConcreteVisitorB *concrete_visitor_b_constructor()
{
  // printf("\r\n concrete_visitor_b_constructor() [构建ConcreteVisitorB]");
  Element *ele = (Element *)malloc(sizeof(Element));
  ConcreteVisitorB *ele_b = (ConcreteVisitorB *)ele;
  strcpy(ele_b->name, "Apple Visitor(struct=ConcreteVisitorB)");
  ele_b->visit_a = &concrete_visitor_b_visit_a;
  ele_b->visit_b = &concrete_visitor_b_visit_b;
  return ele_b;
}
