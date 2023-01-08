# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from abc import abstractmethod, ABCMeta

# 访问者Visitor抽象接口，定义visit方法，传递元素对象
class Visitor(metaclass=ABCMeta):

    @abstractmethod
    def visit(self, concreteElement):
        pass

    def get_name(self):
        pass
