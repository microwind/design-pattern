# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.State import State

# 为避免状态类之间import时相互循环依赖，将import延迟，并通过统一入口获取实例
# 这是python的特殊之处
class ConcreteFactory(State):

    @staticmethod
    def get(state):
        from src.ConcreteStateOn import ConcreteStateOn
        from src.ConcreteStateOff import ConcreteStateOff
        if state == 'on':
            return ConcreteStateOn()
        elif state == 'off':
            return ConcreteStateOff()
        return None
