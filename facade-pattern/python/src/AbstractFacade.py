# -*- coding: utf-8 -*-
"""
@author: jarry
"""

# 外观模式的接口或抽象类，可选
from abc import abstractmethod, ABCMeta


class AbstractFacade(metaclass=ABCMeta):

    @abstractmethod
    def encoding(self, id):
        pass

    @abstractmethod
    def encrypt(id):
        pass
