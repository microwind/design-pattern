#include "func.h"

// 具体访问者A

void concrete_visitor_a_visit_a(ConcreteElementA *ele)
{
  printf("\r\n ConcreteVisitorA::visit_a() [Element.name = %s]", ele->name);
  ele->operate(ele);
}

void concrete_visitor_a_visit_b(ConcreteElementB *ele)
{
  printf("\r\n ConcreteVisitorA::visit_b() [Element.name = %s]", ele->name);
  ele->operate(ele);
}

ConcreteVisitorA *concrete_visitor_a_constructor()
{
  // printf("\r\n concrete_visitor_a_constructor() [构建ConcreteVisitorA]");
  Element *ele = (Element *)malloc(sizeof(Element));
  ConcreteVisitorA *ele_a = (ConcreteVisitorA *)ele;
  strcpy(ele_a->name, "Google Visitor(struct=ConcreteVisitorA)");
  ele_a->visit_a = &concrete_visitor_a_visit_a;
  ele_a->visit_b = &concrete_visitor_a_visit_b;
  return ele_a;
}
