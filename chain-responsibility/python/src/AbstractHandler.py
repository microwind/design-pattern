# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from abc import abstractmethod, ABCMeta

# 抽象处理类，所有处理变成链式，可以互动干涉，动态组合
class AbstractHandler(metaclass=ABCMeta):

    def __init__(self):
        self.next = None

    # 创建调用链，传入多个handler，按顺序形成链，返回第一个handler。static不用设置self
    @staticmethod
    def link(first, *chain):
        head = first
        for handler in chain:
            head.next = handler
            head = handler
        return first

    # 子类需要实现的检查方法
    @abstractmethod
    def check(self, uid):
        pass

    # 继续下一个检查
    def checkNext(self, uid):
        if self.next is None:
            return True

        return self.next.check(uid)
