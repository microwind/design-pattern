#include "func.h"

// 具体装饰器2，实现基础装饰器接口
void shadow_shape_decorator_draw(ShadowShapeDecorator *decorator)
{
  printf("\r\n ShadowShapeDecorator::draw() [name=%s]", decorator->name);
  // 装饰器根据需要是否也调用形状的draw方法
  // decorator->decorated_shape->draw((ShapeDecorator *)decorator);
  decorator->set_shadow(decorator);
}

void decorator_set_shadow(ShadowShapeDecorator *decorator)
{
  printf("\r\n ShadowShapeDecorator::set_shadow() [name=%s]", decorator->name);
}

// 创建ShadowShapeDecorator对象
ShadowShapeDecorator *shadow_shape_decorator_constructor(char *name, ShapeDecorator *decorated_shape)
{
  ShapeDecorator *decorator = (ShapeDecorator *)malloc(sizeof(ShapeDecorator));
  strncpy(decorator->name, name, 50);
  // 转为ShadowShapeDecorator
  ShadowShapeDecorator *shadow_shape_decorator = (ShadowShapeDecorator *)decorator;
  shadow_shape_decorator->decorated_shape = decorated_shape;
  shadow_shape_decorator->draw = &shadow_shape_decorator_draw;
  shadow_shape_decorator->set_shadow = &decorator_set_shadow;
  return shadow_shape_decorator;
}