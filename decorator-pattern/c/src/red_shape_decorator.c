#include "func.h"

// 具体装饰器1，实现基础装饰器接口
void red_shape_decorator_draw(RedShapeDecorator *decorator)
{
  printf("\r\n RedShapeDecorator::draw() [name=%s]", decorator->name);
  decorator->decorated_shape->draw((ShapeDecorator *)decorator);
  decorator->set_red_color(decorator);
}

void decorator_set_red_color(RedShapeDecorator *decorator)
{
  printf("\r\n RedShapeDecorator::set_red_color() [name=%s]", decorator->name);
}

// 创建RedShapeDecorator对象
RedShapeDecorator *red_shape_decorator_constructor(char *name, ShapeDecorator *decorated_shape)
{
  ShapeDecorator *decorator = (ShapeDecorator *)malloc(sizeof(ShapeDecorator));
  strncpy(decorator->name, name, 50);
  // 转为RedShapeDecorator
  RedShapeDecorator *red_shape_decorator = (RedShapeDecorator *)decorator;
  red_shape_decorator->draw = &red_shape_decorator_draw;
  red_shape_decorator->decorated_shape = decorated_shape;
  red_shape_decorator->set_red_color = &decorator_set_red_color;
  return red_shape_decorator;
}