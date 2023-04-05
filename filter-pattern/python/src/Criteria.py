# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from abc import abstractmethod, ABCMeta


# 定义抽象标准接口，聚合实体对象
# python3 声明抽象类
# class Criteria(metaclass=ABCMeta):
class Criteria():
    # python2 ，声明抽象类
    __metaclass__ = ABCMeta

    @abstractmethod
    def filter(self, persons):
        pass
