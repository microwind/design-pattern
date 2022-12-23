# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.Circle import Circle
from src.Rectangle import Rectangle
from src.Square import Square
from src.Shape import Shape

class Application():
    shapes = []

    def add_to_shapes(self):
        circle = Circle()
        circle.set_width(10)
        circle.set_height(20)
        circle.set_color('red')
        self.shapes.append(circle)

        # 添加clone
        anotherCircle = circle.clone()
        anotherCircle.set_color('pink')
        self.shapes.append(anotherCircle)
        # 变量 `anotherCircle（另一个圆）`与 `circle（圆）`对象的内容完全一样。

        rectangle = Rectangle()
        rectangle.set_width(99)
        rectangle.set_height(69)
        rectangle.set_color('green')
        self.shapes.append(rectangle)
        # 添加clone
        self.shapes.append(rectangle.clone())

    def get_shape(self, index):
        return self.shapes[index]

    def get_shape_clone(self, index):
        shape = self.shapes[index]
        if (shape):
            return shape.clone()

    def print_shapes(self):
        for i in range(len(self.shapes)):
            shape = self.shapes[i]
            print('shape ', i , ' : ', shape.to_string())
