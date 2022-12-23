# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.Shape import Shape

class Square(Shape):

  def __init__(self):
    # Shape.__init__(self)
    self.type = 'Square'

  def draw(self):
    print('Square::draw()')