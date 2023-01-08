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
    * 状态模式就是不同的状态下有不同的行为，当前对象只有一种状态
    * 策略模式可以重新设置策略，状态则通过动作来切换
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
Context::setState() [state = ConcreteStateOff]
ConcreteStateOff::on() [turn ON ok!]
Context::setState() [state = ConcreteStateOn]
ConcreteStateOn::on() [needn't switch, state is ON.]
ConcreteStateOn::off() [needn't switch, state is OFF.]
Context::setState() [state = ConcreteStateOff]
ConcreteStateOff::off() [needn't switch, state is OFF.]
context.state: ConcreteStateOff
'''