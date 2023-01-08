# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from abc import abstractmethod, ABCMeta


# 定义抽象标准接口，聚合实体对象
class Criteria(metaclass=ABCMeta):

    @abstractmethod
    def filter(self, persons):
        pass
