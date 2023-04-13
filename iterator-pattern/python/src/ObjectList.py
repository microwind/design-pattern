# -*- coding: utf-8 -*-
"""
@author: jarry
"""
# 文件模块

# 无需共享的角色，每次都是新实例

from src.Container import Container
from src.ObjectIterator import ObjectIterator

# class UnsharedConcreteFlyweight:


# 对象列表，是一种数据容器，可以创建一个迭代器
class ObjectList(Container):

    def __init__(self):
        Container.__init__(self)
        # 默认数据
        self.objects = []

    def createIterator(self):
        print(
            self.__class__.__name__ +
            '::createIterator() [获取迭代器 ObjectIterator]', )
        # 把当前对象传给迭代器
        return ObjectIterator(self)

    def setObjects(self, objects):
        self.objects = objects

    def size(self):
        return len(self.objects)

    def get(self, index):
        return self.objects[index]
