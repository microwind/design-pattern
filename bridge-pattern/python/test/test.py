# -*- coding: utf-8 -*-
"""
@author: jarry
"""
import sys
import os

os_path = os.getcwd()
sys.path.append(os_path)

from src.Circle import Circle
from src.DrawStyleA import DrawStyleA
from src.DrawStyleB import DrawStyleB

def test():
    # 声明具体对象，并指定具体工具
    circle = Circle(DrawStyleA())
    # 调用对象的方法，里面执行了工具类的方法
    circle.draw(10, 20, 50)
    # 还可以调用父类里的方法
    circle.draw_done()

    # /*********************** 分割线 ******************************************/

    # 声明具体对象，并指定另外的工具
    circle2 = Circle(DrawStyleB())
    # 调用对象的方法，里面执行了工具类的方法
    circle2.draw(11, 22, 33)
    # 还可以调用父类里的方法
    circle2.draw_done()


if __name__ == '__main__':
    print(__file__)
    print("test start:")
    test()
'''
jarry@jarrys-MacBook-Pro python % python -V
Python 2.7.16

jarry@jarrys-MacBook-Pro python % python test/test.py
test start:
Circle::draw() [x= 10 y= 20 radius= 50 ]
DrawStyleA:draw_tyle()
RefinedShape::draw_done(), 执行的drawTool是:  DrawStyleA
Circle::draw() [x= 11 y= 22 radius= 33 ]
DrawStyleB:draw_tyle()
RefinedShape::draw_done(), 执行的drawTool是:  DrawStyleB


D:\design-pattern\bridge-pattern\python> python -V
Python 3.11.1
jarry@jarrys-MacBook-Pro python % python test/test.py
test start:
Circle::draw() [x= 10 y= 20 radius= 50 ]
DrawStyleA:draw_tyle()
RefinedShape::draw_done(), 执行的drawTool是:  DrawStyleA
Circle::draw() [x= 11 y= 22 radius= 33 ]
DrawStyleB:draw_tyle()
RefinedShape::draw_done(), 执行的drawTool是:  DrawStyleB
'''
