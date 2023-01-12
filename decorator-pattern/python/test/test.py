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
    '''
     * 装饰器模式是将一个对象放到一个装饰器对象中，执行装饰器类里的方法时，对象的行为能力得到增强。
     * 先声明具体对象，然后放到装饰器，得到一个带有装饰器的新对象，该对象具备了新的能力。
    '''

    # 声明形状
    circle = Circle()
    square = Square()

    # 增加红色装饰
    red_circle = RedShapeDecorator(circle)
    red_square = RedShapeDecorator(square)
    circle.draw()
    red_circle.draw()
    red_square.draw()

    # 增加影子装饰
    shadow_circle = ShadowShapeDecorator(circle)
    shadow_square = ShadowShapeDecorator(square)
    shadow_circle.draw()
    shadow_square.draw()


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
Square::draw()
RedShapeDecorator::set_red_color() Square
ShadowShapeDecorator::set_shadow() Circle
ShadowShapeDecorator::set_shadow() Square
'''
