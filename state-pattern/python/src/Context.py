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

    def get_state(self):
        return self.state

    def set_state(self, state):
        print(self.__class__.__name__ + '::set_state() [state = ' +
              state.__class__.__name__ + ']')
        self.state = state

    def turn_on(self):
        self.state.on(self)

    def turn_off(self):
        self.state.off(self)
