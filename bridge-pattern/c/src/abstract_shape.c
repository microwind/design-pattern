#include "func.h"

/* 定义抽象形状类，关联图形操作接口，相当于桥接 */

// 给形状对象绑定工具对象，共用函数
void set_draw_tool(AbstractShape *shape, struct DrawTool *draw_tool)
{
  printf("\r\n RefinedShape::set_draw_tool() [name=%s", draw_tool->name);
  shape->draw_tool = draw_tool;
}

// 获取形状对象绑定的工具函数
DrawTool *get_draw_tool(AbstractShape *shape)
{
  return shape->draw_tool;
}
