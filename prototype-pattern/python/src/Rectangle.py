# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.Shape import Shape

class Rectangle(Shape):

  def __init__(self):
    self.type = 'Rectangle'

  def draw(self):
    print('Rectangle::draw()')