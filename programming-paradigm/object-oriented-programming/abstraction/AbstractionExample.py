# -*- coding: utf-8 -*-
'''
抽象是一种简化复杂系统的方法，在更高层次上进行建模。抽象包括两个方面，一是过程抽象，二是数据抽象。
抽象类：Shape是一个抽象类，它包含一个抽象方法calculateArea()。抽象类通过abstract关键字进行声明，不能被实例化。
抽象类（Abstract Class）和接口（Interface）是不同的机制，用于实现多态性和代码组织。两者都可以用于定义抽象方法，但又有区别。
抽象类用于表示一种"is-a"关系，而接口用于表示一种"can-do"关系。
Python没有抽象类，但由于抽象方法。Python也无需父类声明子类。
'''
from abc import ABC, abstractmethod
import math

# 抽象类：形状
class Shape(ABC):
    # 抽象方法：计算形状的面积。由子类具体实现
    @abstractmethod
    def calculate_area(self):
        pass

# 子类：圆形
class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius  # 圆的半径

    # 实现抽象方法：计算圆的面积
    def calculate_area(self):
        return math.pi * self.radius ** 2

# 子类：矩形
class Rectangle(Shape):
    def __init__(self, width, height):
        self.width = width  # 矩形的宽度
        self.height = height  # 矩形的高度

    # 实现抽象方法：计算矩形的面积
    def calculate_area(self):
        return self.width * self.height

# 子类：三角形
class Triangle(Shape):
    def __init__(self, base, height):
        self.base = base  # 三角形的底边长
        self.height = height  # 三角形的高

    # 实现抽象方法：计算三角形的面积
    def calculate_area(self):
        return 0.5 * self.base * self.height

# 测试验证
if __name__ == "__main__":
    # 创建圆形对象并计算面积
    circle = Circle(5)
    circle_area = circle.calculate_area()
    print("圆形面积:", circle_area)  # 输出：圆形面积: 78.53981633974483

    # 创建矩形对象并计算面积
    rectangle = Rectangle(4, 6)
    rectangle_area = rectangle.calculate_area()
    print("矩形面积:", rectangle_area)  # 输出：矩形面积: 24

    # 创建三角形对象并计算面积
    triangle = Triangle(3, 4)
    triangle_area = triangle.calculate_area()
    print("三角形面积:", triangle_area)  # 输出：三角形面积: 6.0

'''
jarry@jarrys-MacBook-Pro abstraction % python -V
Python 3.8.2
jarry@jarrys-MacBook-Pro abstraction % python AbstractionExample.py
圆形面积: 78.53981633974483
矩形面积: 24
三角形面积: 6.0
'''