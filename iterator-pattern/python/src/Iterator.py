# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from abc import abstractmethod, ABCMeta


# 迭代器抽象接口，提供next和hasNext方法
class Iterator(metaclass=ABCMeta):

    @abstractmethod
    def hasNext():
        pass

    @abstractmethod
    def next():
        pass
