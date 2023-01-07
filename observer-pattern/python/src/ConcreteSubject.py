# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.Subject import Subject


# 观察者主题类，也是发布者，重写具体的通知方法。不同主题可以关联不同的观察者。
class ConcreteSubject(Subject):
    # 不同的主题类有自己的通知方法，批量通知绑定的观察者
    def notify(self, content):
        print(self.__class__.__name__ + '::notify() [content = ' + content +
              ']')
        for observer in self.observers:
            observer.update(content)
