# -*- coding: utf-8 -*-
"""
@author: jarry
"""

# 定义状态接口和状态方法，当前context只有一种状态
from abc import abstractmethod, ABCMeta


class State(metaclass=ABCMeta):

    @abstractmethod
    def on(context):
        pass

    @abstractmethod
    def off(context):
        pass
