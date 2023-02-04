# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.AbstractShape import AbstractShape

# 具体桥接类，继承抽象桥接类，扩充了自己的方法
# 也可以将此类当做抽象类，再往下派生具体实现类

class RefinedShape(AbstractShape):

    def __init__(self, draw_tool):
        AbstractShape.__init__(self, draw_tool)

    def draw(self, x, y, radius):
        print('RefinedShape::draw() [x=', x, 'y=', y, 'radius=', radius, ']')
        # 通过工具类实际绘制
        self.draw_tool.draw_style()

    def draw_done(self):
        print('RefinedShape::draw_done(), 执行的drawTool是: ')
        print(self.draw_tool.__class__.__name__)
