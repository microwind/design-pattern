# -*- coding: utf-8 -*-
"""
@author: jarry
"""


# 具体执行实体类，内部关联状态
class Context:

    def __init__(self, state):
        self.state = state

    def __init__(self):
        self.state = None

    def getState(self):
        return self.state

    def setState(self, state):
        print(self.__class__.__name__ + '::setState() [state = ' +
              state.__class__.__name__ + ']')
        self.state = state

    def turnOn(self):
        self.state.on(self)

    def turnOff(self):
        self.state.off(self)
