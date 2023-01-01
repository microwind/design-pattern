# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from abc import abstractmethod, ABCMeta

# 享元角色抽象接口
class Flyweight(metaclass=ABCMeta):

    @abstractmethod
    def __init__(self, name):
        self.name = name

    @abstractmethod
    def operate(self, state):
        pass
