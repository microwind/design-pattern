# -*- coding: utf-8 -*-
"""
@author: jarry
"""

# 抽象工厂接口/父类，用于规范具体工厂
class AbstractFactory():

    def __init__(self, ):
        print('AbstractFactory init.')

    def get_vehicle(self):
        return None

    def get_shop(self):
        return None

'''
# Python不具有抽象类，Python3可通过导入abc模块可以定义抽象类和抽象方法。

from abc import abstractmethod, ABCMeta
class AbstractFactory(metaclass=ABCMeta):

    def __init__(self, ):
      print('AbstractFactory init.')

    @abstractmethod
    def get_vehicle(self):
        return None

    @abstractmethod
    def get_shop(self):
        return None
'''
