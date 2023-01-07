# -*- coding: utf-8 -*-
"""
@author: jarry
"""


# 观察者抽象父类，定义一些公共方法
class ObserverAPI:

    def __init__(self, name):
        self.name = name

    # 观察者发出更新通知，观察者自行监听
    def update(self, content):
        print(self.__class__.__name__ + '::update() [content = ' + content + ']')

    def set_name(self, name):
        self.name = name
