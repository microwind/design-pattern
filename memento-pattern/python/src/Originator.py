# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.Memento import Memento


# 发起人(Originator)负责生成状态快照，即利用一个新备忘录对象将自己的内部状态存储起来
class Originator:

    def __init__(self):
        self.state = None

    # 每次创建一个新备忘录来保存状态
    def saveMemento(self):
        print(self.__class__.__name__ + '::saveMemento() [state = ' +
              self.state + ']')
        return Memento(self.state)

    # 从备忘录中恢复状态
    def restoreMemento(self, memento):
        self.state = memento.getState()

    def getState(self):
        return self.state

    def setState(self, state):
        self.state = state
