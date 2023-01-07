# -*- coding: utf-8 -*-
"""
@author: jarry
"""

# 备忘录(Memento)角色，负责存储发起人传入的状态
class Memento:

    def __init__(self, state):
        print(self.__class__.__name__ + '::Memento() [state = ' + state + ']')
        self.state = state

    def getState(self):
        return self.state

    def setState(self, state):
        self.state = state
