#include "func.h"

// 重新定义draw函数
void rectangle_draw(Rectangle *shape)
{
  printf("\r\n Rectangle::draw()");
}

Rectangle *rectangle_constructor(char *name)
{
  printf("\r\n shape_constructor() [构建Rectangle]");
  Shape *shape = (Shape *)shape_constructor(name);
  Rectangle *rectangle = (Rectangle *)shape;
  rectangle->draw = &rectangle_draw;
  return rectangle;
}