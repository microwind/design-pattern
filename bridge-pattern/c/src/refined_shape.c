#include "func.h"

/* 基础形状的实现类，绑定具体工具对象 */

// 实现draw函数
void refined_shape_draw(AbstractShape *shape, int x, int y, int radius)
{
  printf("\r\n RefinedShape::draw() [x=%d y=%d radius=%d]", x, y, radius);
  // 通过工具类实现具体功能
  if (shape->draw_tool != NULL)
  {
    shape->draw_tool->draw_style(shape);
  }
}

// draw_done，可作为具体工具的补充
void refined_shape_draw_done(RefinedShape *shape)
{
  DrawTool *draw_tool = shape->get_draw_tool((AbstractShape *)shape);
  char *draw_tool_name = draw_tool->get_name(draw_tool);
  printf("\r\n RefinedShape::draw_done(), 执行的DrawTool是: %s", draw_tool_name);
}

// 具体形状类的构造函数
RefinedShape *refined_shape_constructor(char *name)
{
  printf("\r\n refined_shape_constructor() [name=%s]", name);
  AbstractShape *shape = (AbstractShape *)malloc(sizeof(AbstractShape));
  strncpy(shape->name, name, 50);
  shape->set_draw_tool = &set_draw_tool;
  shape->get_draw_tool = &get_draw_tool;
  shape->draw = &refined_shape_draw;
  // 转为具体形状对象，并绑定新的方法
  RefinedShape *refined_shape = (RefinedShape *)shape;
  refined_shape->draw_done = &refined_shape_draw_done;
  return refined_shape;
}