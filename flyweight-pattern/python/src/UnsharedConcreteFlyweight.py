# -*- coding: utf-8 -*-
"""
@author: jarry
"""
# 文件模块

# 无需共享实例的角色，用于处理外部非共享状态
# 当不需要共享时用这样的类

from src.Flyweight import Flyweight
# class UnsharedConcreteFlyweight:
class UnsharedConcreteFlyweight(Flyweight):
    def __init__(self, name):
        self.name = name
        self.type = 'guitar'
        print('UnsharedConcreteFlyweight::__init__(name) [创建非共享对象' + name + ']')

    # 非共享对象的外部状态
    def operate(self, state):
        print(self.__class__.__name__ +
              '::operate() [' + self.name + ',' + self.type + ',' + state + ']')

    def get_name(self):
        return self.name

    def get_type(self):
        return self.type
