# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.RefinedShape import RefinedShape

# 具体业务类，调用工具来辅助实现功能
class Circle(RefinedShape):

    def __init__(self, draw_tool):
        RefinedShape.__init__(self, draw_tool)

    def draw(self, x, y, radius):
        print('Circle::draw() [x=', x, 'y=', y, 'radius=', radius, ']')
        # 通过工具类实际绘制
        self.draw_tool.draw_style()
