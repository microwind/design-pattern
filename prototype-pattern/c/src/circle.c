#include "func.h"

// 重新定义draw函数
void circle_draw(Circle *shape)
{
  printf("\r\n Circle::draw()");
}

Circle *circle_constructor(char *name)
{
  printf("\r\n shape_constructor() [构建Circle]");
  Shape *shape = (Shape *)shape_constructor(name);
  Circle *circle = (Circle *)shape;
  circle->draw = &circle_draw;
  return circle;
}