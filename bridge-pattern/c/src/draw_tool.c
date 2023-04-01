#include "func.h"

/* 图形操作基础接口draw_tool，c语言以struct表示，定义在head */

// 获取工具的名称，作为具体工具的公共函数，放在基础工具文件中
char *get_draw_tool_name(DrawTool *draw_tool)
{
  return draw_tool->name;
}