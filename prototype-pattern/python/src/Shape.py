# -*- coding: utf-8 -*-
"""
@author: jarry
"""

import copy


class Shape():
    width = 0
    height = 0
    color = ''
    type = None

    def __init__(self):
      print("Shape init")

    def draw(self):
        print('Shape::draw()')

    def set_width(self, width):
        self.width = width

    def get_width(self):
        return self.width

    def get_height(self):
        return self.height

    def set_height(self, height):
        self.height = height

    def set_color(self, color):
        self.color = color

    def get_color(self):
        return self.color

    def clone(self):
        return copy.copy(self)
        # return copy.deepcopy(self)

    def to_string(self):
      # return self.__dict__
      return '{{ width = {0}, height = {1}, type = {2}, color = {3} }}'.format(
            self.width, self.height, self.type, self.color)
