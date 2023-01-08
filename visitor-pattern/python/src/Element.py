# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from abc import abstractmethod, ABCMeta


# 抽象元素(Element)，定义accept方法，传入抽象访问者
class Element(metaclass=ABCMeta):

    @abstractmethod
    def accept(self, visitor):
        pass
