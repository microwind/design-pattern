# -*- coding: utf-8 -*-
"""
@author: jarry
"""

# 负责人(Caretaker)角色，只负责保存备忘录记录，不能修改备忘录对象的内容
class Caretaker:

    def __init__(self):
        # 备忘录可以是一个记录，也可以就是一个对象，根据业务场景设置
        self.memento_list = []

    def add(self, memento):
        print(self.__class__.__name__ + '::add() [memento = ' +
              memento.__class__.__name__ + ']')
        self.memento_list.append(memento)

    def get(self, index):
        return self.memento_list[index]

    def getMementoList(self):
        return self.memento_list
