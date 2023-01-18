# -*- coding: utf-8 -*-
"""
@author: jarry
"""

# 外观模式的接口或抽象类，可选
from src.Flyweight import Flyweight

# 具体享元角色，实现抽象接口，用于共享状态，一个类被创建以后就不用重复创建了
# class ConcreteFlyweight:
class ConcreteFlyweight(Flyweight):
    def __init__(self, name):
        # 内部状态，即不会随着环境的改变而改变的可共享部分
        # 这里的name也是对象保存的key
        self.name = name
        self.type = 'piano'
        print('ConcreteFlyweight::__init__(name) [创建具体享元' + name + ']')
        
    # 这里state属于外部状态，在调用时外部传入。
    def operate(self, state):
        print(self.__class__.__name__ +
              '::operate() [' + self.name + ',' + self.type + ',' + state + ']')

    def get_name(self):
        return self.name

    def get_type(self):
        return self.type
