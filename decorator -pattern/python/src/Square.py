# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.Shape import Shape

# 具体形状实现了基础形状接口


class Square(Shape):
    def draw(self):
        print('Square::draw()')
