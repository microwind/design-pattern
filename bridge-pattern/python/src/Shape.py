# -*- coding: utf-8 -*-
"""
@author: jarry
"""

# 定义抽象形状类，关联图形操作接口
# python用普通类代替亦可
class Shape():
    draw_tool = None

    def __init__(self, draw_tool):
        self.draw_tool = draw_tool

    def draw(x, y, radius):
        pass
