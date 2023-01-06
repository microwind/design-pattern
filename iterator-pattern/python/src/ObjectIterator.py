# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.Iterator import Iterator


# 对象迭代器，实现了抽象迭代器的方法，聚合了对象列表
class ObjectIterator(Iterator):

    def __init__(self, objectList):
        Iterator.__init__(objectList)
        self.index = 0
        self.objectList = objectList

    def hasNext(self):
        if (self.index < self.objectList.size()):
            return True

        return False

    def next(self):
        if (self.hasNext()):
            # 返回数据对象提供的get方法，每访问一次则增加下标
            item = self.objectList.get(self.index)
            self.index += 1
            return item

        return None
