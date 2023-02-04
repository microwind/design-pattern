# -*- coding: utf-8 -*-
"""
@author: jarry
"""
import sys
import os

os_path = os.getcwd()
sys.path.append(os_path)

from src.RefinedShape import RefinedShape
from src.DrawStyleA import DrawStyleA
from src.DrawStyleB import DrawStyleB

def test():
    '''
    * 桥接模式是将基础抽象类作为桥接器，用来连接业务对象和具体动作，将两者充分解耦。
    * 具体对象以抽象对象为父类，实现父类方法。
    * 具体工具类实现统一的工具接口，为抽象桥接对象服务
    * 使用时，声明具体对象同时传入具体工具，使得具体对象可以使用具体工具的动作。
    '''
    # 声明具体对象，并指定具体工具
    shape = RefinedShape(DrawStyleA())
    # 调用对象的方法，里面执行了工具类的方法
    shape.draw(10, 20, 50)
    # 调用具体类的方法
    shape.draw_done()

    # /*********************** 分割线 ******************************************/

    # 声明具体对象，并指定另外的工具
    shape2 = RefinedShape(DrawStyleB())
    # 调用对象的方法，里面执行了工具类的方法
    shape2.draw(11, 22, 33)
    # 调用具体类的方法
    shape2.draw_done()


if __name__ == '__main__':
    print(__file__)
    print("test start:")
    test()
'''
jarry@jarrys-MacBook-Pro python % python -V
Python 2.7.16

jarry@jarrys-MacBook-Pro python % python test/test.py
test start:
('RefinedShape::draw() [x=', 10, 'y=', 20, 'radius=', 50, ']')
DrawStyleA:draw_tyle()
RefinedShape::draw_done(), 执行的drawTool是: 
DrawStyleA
('RefinedShape::draw() [x=', 11, 'y=', 22, 'radius=', 33, ']')
DrawStyleB:draw_tyle()
RefinedShape::draw_done(), 执行的drawTool是: 
DrawStyleBs
'''
