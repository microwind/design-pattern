#include "func.h"

// 实现部件的树枝构件1
void company_composite_operation(CompanyComposite *component)
{
  printf("\r\n CompanyComposite::operation() [name=%s]", component->name);
  print_children(component->children, component->children_size);
  for (int i = 0; i < component->children_size; i++)
  {
    if (component->children[i] != NULL)
    {
      component->children[i]->operation(component->children[i]);
    }
  }
}

// 创建CompanyComposite对象
CompanyComposite *company_composite_constructor(char *name)
{
  OrganizationComponent *component = (OrganizationComponent *)malloc(sizeof(OrganizationComponent));
  strncpy(component->name, name, 200);
  component->add = &add_component;
  component->remove = &remove_component;
  component->children_size = 0;
  component->get_child = &get_child_component;
  // 转为CompanyComposite
  CompanyComposite *company_composite = (CompanyComposite *)component;
  company_composite->operation = &company_composite_operation;
  return company_composite;
}