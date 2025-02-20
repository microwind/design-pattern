/*
抽象是一种简化复杂系统的方法，在更高层次上进行建模。抽象包括两个方面，一是过程抽象，二是数据抽象。
抽象类：Shape是一个抽象类，它包含一个抽象方法calculateArea()。抽象类通过abstract关键字进行声明，不能被实例化。
抽象类（Abstract Class）和接口（Interface）是不同的机制，用于实现多态性和代码组织。两者都可以用于定义抽象方法，但又有区别。
抽象类用于表示一种"is-a"关系，而接口用于表示一种"can-do"关系。
c没有抽象类，可以使用struct替代。
c没有class，可以使用struct替代。
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 定义抽象类：形状
struct Shape
{
  // 抽象方法：计算形状的面积。由子类具体实现
  double (*calculate_area)(void);
};

// 定义子类：圆形
struct Circle
{
  struct Shape base; // 基类
  double radius;     // 圆的半径
};

// 圆形对象的计算面积方法
double circle_calculate_area(void)
{
  struct Circle *circle = (struct Circle *)malloc(sizeof(struct Circle));
  circle->radius = 5; // 圆的半径为 5
  return M_PI * circle->radius * circle->radius;
}

// 创建圆形对象的函数
struct Circle *create_circle(void)
{
  struct Circle *circle = (struct Circle *)malloc(sizeof(struct Circle));
  circle->base.calculate_area = circle_calculate_area;
  return circle;
}

// 定义子类：矩形
struct Rectangle
{
  struct Shape base; // 基类
  double width;      // 矩形的宽度
  double height;     // 矩形的高度
};

// 矩形对象的计算面积方法
double rectangle_calculate_area(void)
{
  struct Rectangle *rectangle = (struct Rectangle *)malloc(sizeof(struct Rectangle));
  rectangle->width = 4;  // 矩形的宽度为 4
  rectangle->height = 6; // 矩形的高度为 6
  return rectangle->width * rectangle->height;
}

// 创建矩形对象的函数
struct Rectangle *create_rectangle(void)
{
  struct Rectangle *rectangle = (struct Rectangle *)malloc(sizeof(struct Rectangle));
  rectangle->base.calculate_area = rectangle_calculate_area;
  return rectangle;
}

// 主函数
int main()
{
  // 创建圆形对象并计算面积
  struct Circle *circle = create_circle();
  double circle_area = circle->base.calculate_area();
  printf("圆形面积: %f\n", circle_area); // 输出：圆形面积: 78.539816

  // 创建矩形对象并计算面积
  struct Rectangle *rectangle = create_rectangle();
  double rectangle_area = rectangle->base.calculate_area();
  printf("矩形面积: %f\n", rectangle_area); // 输出：矩形面积: 24.000000

  // 释放内存
  free(circle);
  free(rectangle);

  return 0;
}

/**
jarry@jarrys-MacBook-Pro abstraction % gcc -v
Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/include/c++/4.2.1
Apple clang version 12.0.0 (clang-1200.0.32.29)
Target: x86_64-apple-darwin19.6.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
jarry@jarrys-MacBook-Pro abstraction % gcc abstraction_example.c
jarry@jarrys-MacBook-Pro abstraction % ./a.out
圆形面积: 78.539816
矩形面积: 24.000000
 */