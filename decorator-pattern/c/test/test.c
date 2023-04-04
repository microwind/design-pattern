#include "../src/func.h"

int main(void)
{
    printf("test start:\r\n");
    /**
     * 装饰器模式是将一个对象放到一个装饰器对象中，执行装饰器类里的方法时，对象的行为能力得到增强。
     * 先声明具体对象，然后放到装饰器，得到一个带有装饰器的新对象，该对象具备了新的能力。
     */

    // 声明两个形状对象
    Shape *circle = (Shape *)circle_constructor("circle");
    Square *square = square_constructor("square");

    // 增加红色装饰器
    RedShapeDecorator *red_circle = red_shape_decorator_constructor("red_circle", (ShapeDecorator *)circle);
    ShapeDecorator *red_square = (ShapeDecorator *)red_shape_decorator_constructor("red_square", (ShapeDecorator *)square);
    circle->draw(circle);
    red_circle->draw(red_circle);
    red_square->draw(red_square);

    // 增加影子装饰器
    ShapeDecorator *shadow_circle = (ShapeDecorator *)shadow_shape_decorator_constructor("shadow_circle", (ShapeDecorator *)circle);
    ShadowShapeDecorator *shadow_square = shadow_shape_decorator_constructor("shadow_square", (ShapeDecorator *)square);
    shadow_circle->draw(shadow_circle);
    shadow_square->draw(shadow_square);

    free(circle);
    free(square);
    free(red_circle);
    free(red_square);
    free(shadow_circle);
    free(shadow_square);

    return 0;
}

/**
jarry@jarrys-MacBook-Pro c % gcc test/test.c src/*.c
jarry@jarrys-MacBook-Pro c % ./a.out
test start:

 Circle::draw() [name=circle]
 RedShapeDecorator::draw() [name=red_circle]
 Circle::draw() [name=red_circle]
 RedShapeDecorator::set_red_color() [name=red_circle]
 RedShapeDecorator::draw() [name=red_square]
 Square::draw() [name=red_square]
 RedShapeDecorator::set_red_color() [name=red_square]
 ShadowShapeDecorator::draw() [name=shadow_circle]
 ShadowShapeDecorator::set_shadow() [name=shadow_circle]
 ShadowShapeDecorator::draw() [name=shadow_square]
 ShadowShapeDecorator::set_shadow() [name=shadow_square]%
 */