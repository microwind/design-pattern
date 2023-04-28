#include "func.h"

// 结构对象(ObjectStructure)

void object_add_element(ObjectStructure *structure, Element *ele)
{
  // printf("\r\n ObjectStructure::add_element() [ele = %s]", ele->name);
  structure->elements_length += 1;
  Element **new_elements = (Element **)calloc(structure->elements_length, sizeof(Element));
  // 复制原有数组，并追加新内容到新数组
  for (int i = 0; i < structure->elements_length - 1; i++)
  {
    new_elements[i] = structure->elements[i];
  }
  new_elements[structure->elements_length - 1] = ele;
  free(structure->elements);
  // 指向新数组
  structure->elements = new_elements;
}

// 传入访问者分发给其他元素
void object_accept(ObjectStructure *structure, Visitor *visitor)
{
  printf("\r\n ObjectStructure::accept() [Visitor.name = %s]", visitor->name);
  // 通知全部元素成员接受访问者
  for (int i = 0; i < structure->elements_length; i++)
  {
    structure->elements[i]->accept(structure->elements[i], visitor);
  }
}

// 结构对象初始化时聚合了其他元素
void object_structure_init(ObjectStructure *structure)
{
  structure->add_element(structure, (Element *)concrete_element_a_constructor());
  structure->add_element(structure, (Element *)concrete_element_b_constructor());
}

// 结构对象的初始化函数
ObjectStructure *object_structure_constructor()
{
  printf("\r\n object_structure_constructor() [构建ObjectStructure]");
  ObjectStructure *structure = (ObjectStructure *)malloc(sizeof(ObjectStructure));
  structure->elements_length = 0;
  structure->elements = NULL;
  structure->add_element = &object_add_element;
  structure->accept = &object_accept;
  object_structure_init(structure);
  return structure;
}