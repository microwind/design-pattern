# -*- coding: utf-8 -*-
"""
@author: jarry
"""

# 外观模式的接口或抽象类，可选
from src.Flyweight import Flyweight

# 具体享元角色，实现抽象接口，用于执行实际操作
# class ConcreteFlyweight:
class ConcreteFlyweight(Flyweight):
    def __init__(self, name):
        self.name = name
        self.type = 'piano'
        
    # 这里state属于外部状态，在调用时外部传入。
    def operate(self, state):
        print(self.__class__.__name__ +
              '::operate() [' + self.name + ',' + self.type + ',' + state + ']')

    def get_name(self):
        return self.name

    def get_type(self):
        return self.type
