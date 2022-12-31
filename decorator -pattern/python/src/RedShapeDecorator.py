# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.ShapeDecorator import ShapeDecorator

# 具体装饰器1
class RedShapeDecorator(ShapeDecorator):
  def __init__(self, decorated_shape):
    ShapeDecorator.__init__(self, decorated_shape)
  
  def draw(self):
    self.decorated_shape.draw()
    self.set_red_color(self.decorated_shape)
  

  def set_red_color(self, decorated_shape):
    print(
      'RedShapeDecorator::set_red_color() ' + decorated_shape.__class__.__name__
    )
  
