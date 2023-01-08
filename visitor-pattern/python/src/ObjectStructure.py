# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.ConcreteElementA import ConcreteElementA
from src.ConcreteElementB import ConcreteElementB


# 结构对象(ObjectStructure)
class ObjectStructure:

    def __init__(self):
        # 可以想象为一台电脑，聚合了各种设备元素
        self.name = 'Computer Structure'
        self.elements = []
        # 结构对象初始化聚合了其他元素
        self.addElement(ConcreteElementA())
        self.addElement(ConcreteElementB())

    def addElement(self, element):
        self.elements.append(element)

    # 传入访问者分发给其他元素
    def accept(self, visitor):
        print('ObjectStructure::accept() [visitor.class = ' +
              visitor.__class__.__name__ + ' visitor.name = ' +
              visitor.get_name() + ']')
        for element in self.elements:
            element.accept(visitor)

    def get_name(self):
        return self.name
