#include "func.h"

/* 具体工具类，实现基础工具draw_tool的定义 */

// 具体工具A，实现了基础工具的draw_style API
void draw_style_a_draw_style(AbstractShape *shape)
{
  printf("\r\n DrawStyleA::draw_style()");
}

// DrawStyleA工具对象的构造函数
DrawStyleA *draw_style_a_constructor(char *name)
{
  DrawTool *draw_tool = (DrawTool *)malloc(sizeof(DrawTool));
  strncpy(draw_tool->name, name, 50);
  draw_tool->get_name = &get_draw_tool_name;
  draw_tool->draw_style = &draw_style_a_draw_style;
  // 转为DrawStyleA
  DrawStyleA *draw_tool_a = (DrawStyleA *)draw_tool;
  return draw_tool_a;
}