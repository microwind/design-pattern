#include "func.h"

// 具体形状实现了基础形状接口
void circle_draw(Circle *circle)
{
  printf("\r\n Circle::draw() [name=%s]", circle->name);
}

// 创建Circle对象
Circle *circle_constructor(char *name)
{
  Shape *shape = (Shape *)malloc(sizeof(Shape));
  strncpy(shape->name, name, 50);
  // 转为Circle
  Circle *circle = (Circle *)shape;
  circle->draw = &circle_draw;
  return circle;
}