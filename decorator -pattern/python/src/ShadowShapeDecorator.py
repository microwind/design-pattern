# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.ShapeDecorator import ShapeDecorator
# 具体装饰器2


class ShadowShapeDecorator(ShapeDecorator):
    def __init__(self, decorated_shape):
        ShapeDecorator.__init__(self, decorated_shape)

    def draw(self):
        # self.decorated_shape.draw();
        self.set_shadow(self.decorated_shape)

    def set_shadow(self, decorated_shape):
        print(
            'ShadowShapeDecorator::set_shadow() ' + decorated_shape.__class__.__name__
        )
