# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from abc import abstractmethod, ABCMeta


# 创建抽象容器接口，创建一个迭代器
# 使用抽象类需要使用python3
class Container(metaclass=ABCMeta):
    # class Container:
    @abstractmethod
    def createIterator(sefl):
        pass
