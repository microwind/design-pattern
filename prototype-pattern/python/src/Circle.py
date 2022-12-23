# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.Shape import Shape

class Circle(Shape):

  def __init__(self):
    self.type = 'Circle'

  def draw(self):
    print('Circle::draw()')