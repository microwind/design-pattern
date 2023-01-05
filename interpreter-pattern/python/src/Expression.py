# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from abc import abstractmethod, ABCMeta

# 抽象表达式接口，根据业务场景规范表达式
# 使用抽象类需要使用python3
class Expression(metaclass=ABCMeta):

    @abstractmethod
    def interpret(self, context):
        pass
