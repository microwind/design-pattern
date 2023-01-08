# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.Visitor import Visitor


# 具体访问者A
class ConcreteVisitorA(Visitor):

    def __init__(self):
        Visitor.__init__(self)
        # 假如由不同厂商是程序的访问者
        self.name = 'Google Visitor'

    def visit(self, concreteElement):
        print('ConcreteVisitorA::visit() [Element.class = ' +
              concreteElement.__class__.__name__ + ' Element.name = ' +
              concreteElement.get_name() + ']')
        concreteElement.operate()

    def get_name(self):
        return self.name
