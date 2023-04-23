#include "../src/func.h"

int main(void)
{
  printf("test start:\r\n");
  /**
   * 原型模式主要就是复制已有的对象，而无需实例化类，从而提升实例化对象时的性能
   * 其实就是复制实例的属性到新对象上，减少了执行构造的步骤。
   */
  Application *application = application_constructor();
  application->add_to_shapes(application);
  Shape *shape_clone = application->get_shape_clone(application, 0);
  // SetColor需要接口中定义
  shape_clone->set_color(shape_clone, "gray");
  printf("\r\n shape_clone : %s", shape_clone->to_string(shape_clone));
  // 直接更改
  // application->get_shape(application, 3)->set_color(application->get_shape(application, 3), "yellow");
  application->print_shapes(application);

  /*********************** 分割线 ******************************************/
  // 追加一个Squre实例，相关属性为空
  application->add_shape(application, (Shape *)square_constructor("square"));
  // 打不打印查看结果

  for (int i = 0; i < application->shapes_length; i++)
  {
    Shape *shape = application->shapes[i];
    shape->draw(shape);
    printf("\r\n shape_%d %s", i, shape->to_string(shape));
  }
}

/**
jarry@jarrys-MacBook-Pro c % gcc test/test.c ./src下*.c
jarry@jarrys-MacBook-Pro c % ./a.out
test start:

 application_constructor() [构建Application]
 shape_constructor() [构建Circle]
 shape_constructor() [构建Shape]
 shape_constructor() [构建Rectangle]
 shape_constructor() [构建Shape]
 shape_clone : [name = circle(clone) width = 10, height = 20, category = Circle, color = gray]
 shape0: [name = circle width = 10, height = 20, category = Circle, color = red]
 shape1: [name = circle(clone) width = 10, height = 20, category = Circle, color = pink]
 shape2: [name = rectangle width = 99, height = 69, category = Rectangle, color = green]
 shape3: [name = rectangle(clone) width = 99, height = 69, category = Rectangle, color = green]
 shape_constructor() [构建Square]
 shape_constructor() [构建Shape]
 Circle::draw()
 shape_0 [name = circle width = 10, height = 20, category = Circle, color = red]
 Circle::draw()
 shape_1 [name = circle(clone) width = 10, height = 20, category = Circle, color = pink]
 Rectangle::draw()
 shape_2 [name = rectangle width = 99, height = 69, category = Rectangle, color = green]
 Rectangle::draw()
 shape_3 [name = rectangle(clone) width = 99, height = 69, category = Rectangle, color = green]
 Square::draw()
 shape_4 [name = square width = 0, height = 0, category = , color = ]%  
 */