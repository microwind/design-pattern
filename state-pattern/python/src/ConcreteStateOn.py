# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.State import State
from src.ConcreteFactory import ConcreteFactory

# 具体的状态实现者
class ConcreteStateOn(State):
    
    def on(self, context):
        # 当前是on状态，再点击on只是提示，不切换状态类
        print(self.__class__.__name__ +
              "::on() [needn't switch, state is ON.]")

    def off(self, context):
        # 状态变为off后，状态类切换到ConcreteStateOff
        print(self.__class__.__name__ +
              "::off() [needn't switch, state is OFF.]")
        context.set_state(ConcreteFactory.get('off'))

