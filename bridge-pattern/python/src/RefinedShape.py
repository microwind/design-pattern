# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.Shape import Shape

# 定义新抽象类继承基础抽象类


class RefinedShape(Shape):

    def __init__(self, draw_tool):
        Shape.__init__(self, draw_tool)

    def draw_done(self):
        print('RefinedShape::draw_done(), 执行的drawTool是: ',
              type(self.draw_tool).__name__)
