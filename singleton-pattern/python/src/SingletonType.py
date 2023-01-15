# -*- coding: utf-8 -*-
"""
@author: jarry
"""

'''
基于元类type创建实例
SingletonType就是通过type()来创创建出的类，
它是type()类的一个实例；同时它本身也是类。
'''
class SingletonType(type):
    instance = None
    # def __init__(cls, name, bases, dic):
    #     print('元类的__init__执行')
    #     super().__init__(name, bases, dic)
    #     cls.instance = None

    def __call__(cls, *args, **kwargs):
        if not cls.instance:
            cls.instance = super().__call__(*args, **kwargs)

        return cls.instance

# 继承SingletonType就是单例
class SingletonTypeClass(metaclass=SingletonType):

    def __init__(self, name):
        self.name = name

    def run(self):
        print('SingletonTypeClass::run()', self.name)
