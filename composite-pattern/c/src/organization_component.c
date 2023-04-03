#include "func.h"

// 定义部件接口或抽象类，分支和叶子节点遵循该类约定
// C语言没有接口和抽象类，用struct替代，同时把公共函数声明在这里

// 添加一个组件到子节点中
void add_component(OrganizationComponent *parent, OrganizationComponent *component)
{
  // 先将原数组保留下来
  OrganizationComponent **old_children = parent->children;
  parent->children_size += 1;
  // 新申请空间给子节点数组
  parent->children = (OrganizationComponent **)calloc(parent->children_size, sizeof(OrganizationComponent *));
  for (int i = 0; i < parent->children_size - 1; i++)
  {
    parent->children[i] = old_children[i];
  }
  // 将组件追加到子节点数组中
  parent->children[parent->children_size - 1] = component;
  free(old_children);
}

// 移除第一个匹配的子节点
void remove_component(OrganizationComponent *parent, OrganizationComponent *component)
{
  int size = parent->children_size;
  // 初始化组件id大于数组长度
  int com_idx = size;
  for (int i = 0; i < size; i++)
  {
    // 找到第一个匹配的组件下标
    if (parent->children[i] == component)
    {
      com_idx = i;
    }

    // 自匹配项开始，后项逐个往前移动1位
    if (i >= com_idx)
    {
      parent->children[i] = parent->children[i + 1];
      // 最后一项置空且总长度减少1位
      if (i == size - 1)
      {
        parent->children[i] = NULL;
        parent->children_size -= 1;
      }
    }
  }
}

// 打印全部子节点
void print_children(OrganizationComponent *children[], int children_size)
{
  for (int i = 0; i < children_size; i++)
  {
    // printf("\r\n    children[%d]=%s", i, children[i]->name);
  }
}

// 根据下标获取子节点
OrganizationComponent *get_child_component(OrganizationComponent *component, int index)
{
  return component->children[index];
}