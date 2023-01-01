# -*- coding: utf-8 -*-
"""
@author: jarry
"""
# 文件模块

# 无需共享的角色，每次都是新实例

from src.Flyweight import Flyweight
# class UnsharedConcreteFlyweight:
class UnsharedConcreteFlyweight(Flyweight):
    def __init__(self, name):
        self.name = name
        self.type = 'guitar'

    # 这里state属于外部状态，在调用时外部传入。
    def operate(self, state):
        print(self.__class__.__name__ +
              '::operate() [' + self.name + ',' + self.type + ',' + state + ']')

    def get_name(self):
        return self.name

    def get_type(self):
        return self.type
