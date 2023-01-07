# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.ObserverAPI import ObserverAPI

# 具体的观察者实现类，也可以看成订阅者，关联对应的主题类。
# 不同的观察者也可以对应多个主题


class ConcreteObserver(ObserverAPI):
    # 给观察者绑定主题，同时把观察者添加到主题列表
    def __init__(self, subject, name):
        ObserverAPI.__init__(self, name)
        
        # python3支持的父类调用
        # super(ConcreteObserver, self).__init__(name)
        # super().__init__(name)

        self.subject = subject
        subject.register(self)

    # 观察者发出更新通知，不用单独告诉订阅者，由订阅者自行监听
    def update(self, content):
        print(self.__class__.__name__ + '::update() [subject.name = ' +
              self.subject.name + ' content = ' + content + ']')
