#include "func.h"

// 重新定义draw函数
void square_draw(Square *shape)
{
  printf("\r\n Square::draw()");
}

Square *square_constructor(char *name)
{
  printf("\r\n shape_constructor() [构建Square]");
  Shape *shape = (Shape *)shape_constructor(name);
  Square *square = (Square *)shape;
  square->draw = &square_draw;
  return square;
}