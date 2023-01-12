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
    * 解释器模式实现了一个表达式接口，该接口可以解释一个特定的上下文的变量和语句。
    * 也就是先定义上下文，然后定义变量，再使用表达式进行求值。相当可以构造一个简单的语法解析器。
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
