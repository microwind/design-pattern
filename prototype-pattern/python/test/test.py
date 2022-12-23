# -*- coding: utf-8 -*-
"""
@author: jarry
"""
import sys
import os

os_path = os.getcwd()
sys.path.append(os_path)

from src.Application import Application
from src.Square import Square

def test():
    application = Application()
    application.add_to_shapes()
    shape_clone = application.get_shape_clone(1)
    # 更改clone
    shape_clone.set_color('gray')
    print('shape_clone : ', shape_clone.to_string())
    # 直接更改
    application.get_shape(3).set_color('yellow')
    application.print_shapes()

    # /*********************** 分割线 ******************************************/
    application.shapes.append(Square())
    for shape in application.shapes:
        shape.draw()
        print(shape.to_string())


if __name__ == '__main__':
    print(__file__)
    print("test start:")
    test()
'''
test start:
('shape_clone : ', '{ width = 10, height = 20, type = Circle, color = gray }')
('shape ', 0, ' : ', '{ width = 10, height = 20, type = Circle, color = red }')
('shape ', 1, ' : ', '{ width = 10, height = 20, type = Circle, color = pink }')
('shape ', 2, ' : ', '{ width = 99, height = 69, type = Rectangle, color = green }')
('shape ', 3, ' : ', '{ width = 99, height = 69, type = Rectangle, color = yellow }')
Circle::draw()
{ width = 10, height = 20, type = Circle, color = red }
Circle::draw()
{ width = 10, height = 20, type = Circle, color = pink }
Rectangle::draw()
{ width = 99, height = 69, type = Rectangle, color = green }
Rectangle::draw()
{ width = 99, height = 69, type = Rectangle, color = yellow }
Square::draw()
{ width = 0, height = 0, type = Square, color =  }
'''