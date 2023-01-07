# -*- coding: utf-8 -*-
"""
@author: jarry
"""


# 此类可以是抽象类或者接口，供具体主题类继承
class Subject:

    def __init__(self, name):
        self.name = name
        self.observers = []

    def get_name(self):
        return self.name

    def set_name(self, name):
        self.name = name

    def register(self, observer):
        print(self.__class__.__name__ + '::register() [observer = ' +
              observer.__class__.__name__ + ']')

        self.observers.append(observer)

    def remove(self, observer):
        self.observers.remove(observer)

    # 通知由具体类来实现逻辑
    def notify(self, name):
        pass
