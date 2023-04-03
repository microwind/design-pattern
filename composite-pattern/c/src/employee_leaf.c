#include "func.h"

// 实现部件的叶子节点，叶子节点不能再含有子节点

// 叶子节点不能再增加内容
void add_leaf_component(OrganizationComponent *parent, OrganizationComponent *component)
{
  printf("\r\n Leaf can't add.");
}

// 叶子节点没有移除内容
void remove_leaf_component(OrganizationComponent *parent, OrganizationComponent *component)
{
  printf("\r\n Leaf can't remove.");
}

// 叶子节点不能获取子节点
OrganizationComponent *get_leaf_child_component(OrganizationComponent *component, int index)
{
  printf("\r\n Leaf can't get_child.");
  return NULL;
}

// 子节点的操作函数
void employee_leaf_operation(EmployeeLeaf *component)
{
  printf("\r\n EmployeeLeaf::operation() [name=%s]", component->name);
}

// 创建EmployeeLeaf对象
EmployeeLeaf *employee_leaf_constructor(char *name)
{
  OrganizationComponent *component = (OrganizationComponent *)malloc(sizeof(OrganizationComponent));
  strncpy(component->name, name, 200);
  component->children_size = 0;
  component->add = &add_leaf_component;
  component->remove = &remove_leaf_component;
  component->get_child = &get_leaf_child_component;
  // 转为EmployeeLeaf
  EmployeeLeaf *employee_leaf = (EmployeeLeaf *)component;
  employee_leaf->operation = &employee_leaf_operation;
  return employee_leaf;
}