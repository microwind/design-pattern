#include "func.h"

void app_add_to_shapes(Application *app)
{
  Circle *circle = circle_constructor("circle");
  circle->set_category(circle, "Circle");
  circle->set_width(circle, 10);
  circle->set_height(circle, 20);
  circle->set_color(circle, "red");
  app->add_shape(app, (Shape *)circle);

  // 添加Clone
  Circle *another_circle = circle->clone(circle);
  another_circle->set_color(another_circle, "pink");
  app->add_shape(app, (Shape *)another_circle);
  // 变量 `another_circle（另一个圆）`与 `circle（圆）`对象的内容完全一样。

  Rectangle *rectangle = rectangle_constructor("rectangle");
  rectangle->set_category(rectangle, "Rectangle");
  rectangle->set_width(rectangle, 99);
  rectangle->set_height(rectangle, 69);
  rectangle->set_color(rectangle, "green");
  app->add_shape(app, (Shape *)rectangle);
  // 再添加一个clone
  app->add_shape(app, (Shape *)rectangle->clone(rectangle));
}

void app_add_shape(Application *app, Shape *shape)
{
  app->shapes_length += 1;
  Shape **new_shapes = (Shape **)calloc(app->shapes_length, sizeof(Shape));
  // 复制原有数组，并追加新内容到新数组
  for (int i = 0; i < app->shapes_length - 1; i++)
  {
    new_shapes[i] = app->shapes[i];
  }
  new_shapes[app->shapes_length - 1] = shape;
  free(app->shapes);
  // 指向新数组
  app->shapes = new_shapes;
}

Shape *app_get_shape(Application *app, int index)
{
  return app->shapes[index];
}

Shape **app_get_shapes(Application *app)
{
  return app->shapes;
}

Shape *app_get_shape_clone(Application *app, int index)
{
  Shape *shape = app->shapes[index];
  if (shape != NULL)
  {
    return shape->clone(shape);
  }
  return NULL;
}

void app_print_shapes(Application *app)
{
  for (int i = 0; i < app->shapes_length; i++)
  {
    Shape *shape = app->shapes[i];
    printf("\r\n shape%d: %s", i, shape->to_string(shape));
  }
}

// 给观察者绑定主题，同时把观察者添加到主题列表
Application *application_constructor()
{
  printf("\r\n application_constructor() [构建Application]");
  Application *app = (Application *)malloc(sizeof(Application));
  app->shapes_length = 0;
  app->shapes = (Shape **)calloc(app->shapes_length, sizeof(Shape));
  app->add_to_shapes = &app_add_to_shapes;
  app->add_shape = &app_add_shape;
  app->get_shape = &app_get_shape;
  app->get_shapes = &app_get_shapes;
  app->get_shape_clone = &app_get_shape_clone;
  app->print_shapes = &app_print_shapes;
  return app;
}