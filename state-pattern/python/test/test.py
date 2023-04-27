# -*- coding: utf-8 -*-
"""
@author: jarry
"""

import sys
import os

os_path = os.getcwd()
sys.path.append(os_path)

from src.Context import Context
from src.ConcreteStateOff import ConcreteStateOff
from src.ConcreteStateOn import ConcreteStateOn

def test():
    '''
    * 状态模式就是对象Context在不同行为下有不同的状态，当前只有一种状态。
    * 通过行为的改变，状态也随之自动发生了改变。
    * 策略模式与状态模式类似，但策略模式是可以重新设置策略，而状态则通过行为来切换状态。
    '''

    context = Context()
    # 初始状态是off
    context.set_state(ConcreteStateOff())
    # turn on
    context.turn_on()
    # 再次turn on
    context.turn_on()
    # turn off
    context.turn_off()
    # 再次turn off
    context.turn_off()
    print('context.state: ' + context.get_state().__class__.__name__)


if __name__ == '__main__':
    print(__file__)
    print("test start:")
    test()
'''
jarry@jarrys-MacBook-Pro python % python3 test/test.py
test/test.py
test start:
Context::set_state() [state = ConcreteStateOff]
ConcreteStateOff::on() [turn ON ok!]
Context::set_state() [state = ConcreteStateOn]
ConcreteStateOn::on() [needn't switch, state is ON.]
ConcreteStateOn::off() [turn OFF ok!]
Context::set_state() [state = ConcreteStateOff]
ConcreteStateOff::off() [needn't switch, state is OFF.]
context.state: ConcreteStateOff
'''