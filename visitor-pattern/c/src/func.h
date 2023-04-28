#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct ObjectStructure ObjectStructure;
typedef struct Element Element;
typedef struct ConcreteElementA ConcreteElementA;
typedef struct ConcreteElementB ConcreteElementB;
typedef struct Visitor Visitor;
typedef struct ConcreteVisitorA ConcreteVisitorA;
typedef struct ConcreteVisitorB ConcreteVisitorB;

// 结构对象(ObjectStructure)
typedef struct ObjectStructure
{
  Element **elements;
  int elements_length;
  void (*add_element)(ObjectStructure *structure, Element *ele);
  void (*accept)(ObjectStructure *structure, Visitor *visitor);
} ObjectStructure;
ObjectStructure *object_structure_constructor();

// (Element)抽象结构，提供定义Accept方法，绑定抽象访问者，用struct替代
typedef struct Element
{
  char name[50];
  void (*accept)(Element *e, Visitor *v);
  void (*operate)(Element *e);
} Element;

// 访问者Visitor抽象接口，定义Visit方法，传递具体元素对象
typedef struct Visitor
{
  char name[50];
  void (*visit_a)(ConcreteElementA *e);
  void (*visit_b)(ConcreteElementB *e);
} Visitor;

// 具体访问者A
typedef struct ConcreteVisitorA
{
  char name[50];
  void (*visit_a)(ConcreteElementA *e);
  void (*visit_b)(ConcreteElementB *e);
} ConcreteVisitorA;
ConcreteVisitorA *concrete_visitor_a_constructor();

// 具体访问者B
typedef struct ConcreteVisitorB
{
  char name[50];
  void (*visit_a)(ConcreteElementA *e);
  void (*visit_b)(ConcreteElementB *e);
} ConcreteVisitorB;
ConcreteVisitorB *concrete_visitor_b_constructor();

// 具体的元素实现者A
typedef struct ConcreteElementA
{
  char name[50];
  void (*accept)(ConcreteElementA *e, Visitor *v);
  void (*operate)(ConcreteElementA *e);
} ConcreteElementA;
ConcreteElementA *concrete_element_a_constructor();

// 具体的元素实现者B
typedef struct ConcreteElementB
{
  char name[50];
  void (*accept)(ConcreteElementB *e, Visitor *v);
  void (*operate)(ConcreteElementB *e);
} ConcreteElementB;
ConcreteElementB *concrete_element_b_constructor();