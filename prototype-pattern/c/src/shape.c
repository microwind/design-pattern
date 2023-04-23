#include "func.h"

// shape基础抽象类，供子类继承覆盖
// C没有抽象和继承，此处作为公共类存在
void shape_draw(Shape *shape)
{
  printf("\r\n Shape::draw()");
}

void shape_set_width(Shape *shape, int width)
{
  shape->width = width;
}

int shape_get_width(Shape *shape)
{
  return shape->width;
}

int shape_get_height(Shape *shape)
{
  return shape->height;
}

void shape_set_height(Shape *shape, int height)
{
  shape->height = height;
}

void shape_set_color(Shape *shape, char *color)
{
  strncpy(shape->color, color, 50);
}

char *shape_get_color(Shape *shape)
{
  return shape->color;
}

void shape_set_category(Shape *shape, char *category)
{
  strncpy(shape->category, category, 50);
}

char *shape_get_category(Shape *shape)
{
  return shape->category;
}

char *shape_to_string(Shape *shape)
{
  static char result[1024];
  sprintf(result, "[name = %s width = %d, height = %d, category = %s, color = %s]",
          shape->name, shape->width, shape->height, shape->category, shape->color);
  return result;
}

// 将指针指向同一内存的方式来实现clone
Shape *shape_clone(Shape *shape)
{
  Shape *copy = (Shape *)malloc(sizeof(Shape));
  memcpy(copy, shape, sizeof(Shape));
  strcat(copy->name, "(clone)");
  // printf("\r\n shape_clone: %s", copy->to_string(copy));
  return copy;
}

// 定义简单结构体，复制基本属性和draw函数
Shape *shape_clone2(Shape *shape)
{
  struct Shape copy = {
      .width = shape->width,
      .height = shape->height,
  };
  strcpy(copy.name, shape->name);
  strcat(copy.name, "[clone]");
  strcpy(copy.color, shape->color);
  strcpy(copy.category, shape->category);
  Shape *shape_copy = &copy;
  shape_copy->draw = shape->draw;
  // printf("\r\n shape_clone: %s", shape->to_string(shape_copy));
  return shape_copy;
}

Shape *shape_constructor(char *name)
{
  printf("\r\n shape_constructor() [构建Shape]");
  Shape *shape = (Shape *)malloc(sizeof(Shape));
  strncpy(shape->name, name, 50);
  shape->draw = &shape_draw;
  shape->clone = &shape_clone;
  shape->to_string = &shape_to_string;
  shape->set_width = &shape_set_width;
  shape->get_width = &shape_get_width;
  shape->set_height = &shape_set_height;
  shape->get_height = &shape_get_height;
  shape->set_color = &shape_set_color;
  shape->get_color = &shape_get_color;
  shape->set_category = &shape_set_category;
  shape->get_category = &shape_get_category;
  return shape;
}