#include "func.h"

// 具体形状实现了基础形状接口
void square_draw(Square *square)
{
  printf("\r\n Square::draw() [name=%s]", square->name);
}

// 创建Square对象
Square *square_constructor(char *name)
{
  Shape *shape = (Shape *)malloc(sizeof(Shape));
  strncpy(shape->name, name, 50);
  // 转为Square
  Square *square = (Square *)shape;
  square->draw = &square_draw;
  return square;
}