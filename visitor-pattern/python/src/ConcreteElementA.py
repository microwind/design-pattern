# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.Element import Element


# 具体的元素实现者A
class ConcreteElementA(Element):

    def __init__(self):
        Element.__init__(self)
        # 可以设想为显示器
        self.name = 'Monitor Element'

    def accept(self, visitor):
        print('ConcreteElementA::accept() [visitor.class = ' +
              visitor.__class__.__name__ + ' visitor.name = ' +
              visitor.get_name() + ']')
        visitor.visit(self)

    def operate(self):
        print('ConcreteElementA::operate() [' + self.get_name() + ']')

    def get_name(self):
        return self.name
