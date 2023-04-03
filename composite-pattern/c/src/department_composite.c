#include "func.h"

// 实现部件的树枝构件2
void department_composite_operation(DepartmentComposite *component)
{
  printf("\r\n DepartmentComposite::operation() [name=%s]", component->name);
  print_children(component->children, component->children_size);
  for (int i = 0; i < component->children_size; i++)
  {
    if (component->children[i] != NULL)
    {
      component->children[i]->operation(component->children[i]);
    }
  }
}

// 创建DepartmentComposite对象
DepartmentComposite *department_composite_constructor(char *name)
{
  OrganizationComponent *component = (OrganizationComponent *)malloc(sizeof(OrganizationComponent));
  strncpy(component->name, name, 200);
  component->add = &add_component;
  component->remove = &remove_component;
  component->children_size = 0;
  component->get_child = &get_child_component;
  // 转为DepartmentComposite
  DepartmentComposite *department_composite = (DepartmentComposite *)component;
  department_composite->operation = &department_composite_operation;
  return department_composite;
}