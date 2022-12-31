# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.Shape import Shape

# 抽象装饰类，是否继承Shape可选


class ShapeDecorator(Shape):

    def __init__(self, decorated_shape):
        self.decorated_shape = decorated_shape

    def draw(self):
        self.decorated_shape.draw()
