# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.State import State
from src.ConcreteFactory import ConcreteFactory

# 具体的状态实现者
class ConcreteStateOff(State):

    def on(self, context):
        print(self.__class__.__name__ + '::on() [turn ON ok!]')
        # 状态变为on后，状态类切换到ConcreteStateOn
        context.set_state(ConcreteFactory.get('on'))

    def off(self, context):
        # 当前是off状态，再点击off只是提示，不切换状态类
        print(self.__class__.__name__ +
              "::off() [needn't switch, state is OFF.]")
