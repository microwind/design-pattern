# -*- coding: utf-8 -*-
"""
@author: jarry
"""

import sys
import os

os_path = os.getcwd()
sys.path.append(os_path)

from src.ShadowShapeDecorator import ShadowShapeDecorator
from src.RedShapeDecorator import RedShapeDecorator
from src.Square import Square
from src.Circle import Circle

def test():
    # 声明形状
    circle = Circle()
    square = Square()

    # 增加红色装饰
    red_circle = RedShapeDecorator(circle)
    red_square = RedShapeDecorator(square)
    circle.draw()
    red_circle.draw()
    red_circle.draw()

    # 增加影子装饰
    shadow_circle = ShadowShapeDecorator(circle)
    shadow_circle = ShadowShapeDecorator(square)
    shadow_circle.draw()
    shadow_circle.draw()


if __name__ == '__main__':
    print(__file__)
    print("test start:")
    test()
'''
jarry@jarrys-MacBook-Pro python % python -V
Python 2.7.16

jarry@jarrys-MacBook-Pro python % python test/test.py
test start:
Circle::draw()
Circle::draw()
RedShapeDecorator::set_red_color() Circle
Circle::draw()
RedShapeDecorator::set_red_color() Circle
ShadowShapeDecorator::set_shadow() Square
ShadowShapeDecorator::set_shadow() Square
'''
