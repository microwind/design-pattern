# -*- coding: utf-8 -*-
"""
@author: jarry
"""

import sys
import os

os_path = os.getcwd()
sys.path.append(os_path)

from src.Application import Application


def test():
    '''
    * 命令模式是客户端通过一个命令执行者invoker，去执行某个命令command
    * 而命令则调用了业务类receiver的具体动作，从而完成真正的执行
    '''
    result1 = Application.add_two(1, 2)
    print('result1: ', result1)

    result2 = Application.add_more(1, 2, 3, 4, 5)
    print('result2: ', result2)

    result3 = Application.add_and_subtract(3, 4, 5)
    print('result3: ', result3)


if __name__ == '__main__':
    print(__file__)
    print("test start:")
    test()
'''
jarry@jarrys-MacBook-Pro python % python3 -V
Python 3.8.10

# python2默认不支持metaclass=ABCMeta，如果采用python2则去掉抽象方法即可

jarry@jarrys-MacBook-Pro python % python3 test/test.py
test/test.py
test start:
AddExpression::interpret() [context = Context]
result1:  3
AddExpression::interpret() [context = Context]
AddExpression::interpret() [context = Context]
AddExpression::interpret() [context = Context]
AddExpression::interpret() [context = Context]
result2:  15
SubtractExpression::interpret() [context = Context]
AddExpression::interpret() [context = Context]
result3:  2
'''
