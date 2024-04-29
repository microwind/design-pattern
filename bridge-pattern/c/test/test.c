#include "../src/func.h"

int main(void)
{
  printf("test start:\r\n");
  /**
   * 桥接模式是将基础抽象类作为桥接器，用来连接业务对象和具体动作，将两者充分解耦。
   * 具体对象以抽象对象为父类，实现父类方法。
   * 具体工具类实现统一的工具接口，为抽象桥接对象服务
   * 使用时，声明具体对象同时传入具体工具，使得具体对象可以使用具体工具的动作。
   */

  // 用抽象对象声明具体对象，绑定具体工具
  AbstractShape *shape = (AbstractShape *)refined_shape_constructor("shape1");
  DrawTool *draw_style_a = (DrawTool *)draw_style_a_constructor("DrawStyleA1");
  shape->set_draw_tool(shape, draw_style_a);
  // 调用对象的方法，里面执行了工具类的方法
  shape->draw(shape, 10, 20, 50);
  // 调用具体类的扩充方法
  shape->draw_done(shape);

  free(shape);
  free(draw_style_a);

  /*********************** 分割线 ******************************************/

  // 用具体对象声明对象，绑定具体的工具，传递的类型与抽象声明时的不同
  RefinedShape *shape2 = refined_shape_constructor("shape2");
  DrawStyleB *draw_style_b = draw_style_b_constructor("DrawStyleB1");
  shape2->set_draw_tool((AbstractShape *)shape2, (DrawTool *)draw_style_b);
  // 调用对象的方法，里面执行了工具类的方法
  shape2->draw((AbstractShape *)shape2, 11, 22, 33);
  // 调用具体类的扩充方法
  shape2->draw_done(shape2);

  free(shape2);
  free(draw_style_b);

  return 0;
}

// jarry@jarrys-MacBook-Pro c % gcc test/test.c src/*.c
// jarry@jarrys-MacBook-Pro c % ./a.out
/**
test start:

 refined_shape_constructor() [name=shape1]
 RefinedShape::set_draw_tool() [name=DrawStyleA1
 RefinedShape::draw() [x=10 y=20 radius=50]
 DrawStyleA::draw_style()
 RefinedShape::draw_done(), 执行的DrawTool是: DrawStyleA1
 refined_shape_constructor() [name=shape2]
 RefinedShape::set_draw_tool() [name=DrawStyleB1
 RefinedShape::draw() [x=11 y=22 radius=33]
 DrawStyleB::draw_style()
 RefinedShape::draw_done(), 执行的DrawTool是: DrawStyleB1%
 */