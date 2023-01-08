# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.Element import Element


# 具体的元素实现者B
class ConcreteElementB(Element):

    def __init__(self):
        Element.__init__(self)
        self.name = 'Keyboard Element'

    def accept(self, visitor):
        print('ConcreteElementB::accept() [visitor.class = ' +
              visitor.__class__.__name__ + ' visitor.name = ' +
              visitor.get_name() + ']')
        visitor.visit(self)

    def operate(self):
        print('ConcreteElementB::operate() [' + self.get_name() + ']')

    def get_name(self):
        return self.name
