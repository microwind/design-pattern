# -*- coding: utf-8 -*-
"""
@author: jarry
"""

import sys
import os

os_path = os.getcwd()
sys.path.append(os_path)

from src.AbstractHandler import AbstractHandler
from src.RequestHandler import RequestHandler
from src.UserHandler import UserHandler
from src.AuthHandler import AuthHandler


def test():
    '''
     * 责任链模式核心是打造一个调用处理链，每个处理链都实现抽象类的next方法，从而可以任意组织各种检查行为。
     * 通过改变链内的成员或者调动它们的顺序，允许动态地新增或者删除职责，从而实现按需组织。
     '''

    # 可以任意组织职责链，先后顺序根据需要来
    handler1 = AbstractHandler.link(RequestHandler(), UserHandler(),
                                    AuthHandler())

    print('handler1.check(1001)开始')
    handler1.check(1001)
    print('handler1.check(1002)开始')
    handler1.check(1002)

    # 可以任意组织职责链，先后顺序根据需要来
    handler2 = AbstractHandler.link(AuthHandler(), RequestHandler(),
                                    UserHandler())

    print('handler2.check(1001)开始')
    handler2.check(1001)
    print('handler2.check(1002)开始')
    handler2.check(1002)


if __name__ == '__main__':
    print(__file__)
    print("test start:")
    test()
'''
jarry@jarrys-MacBook-Pro python % python -V
Python 3.11.1

# 这里采取python3，要看下自己的python版本，如果不是python3则去掉抽象类即可。
jarry@jarrys-MacBook-Pro python % python3 test/test.py
test start:
handler1.check(1001)开始
RequestHandler::check() [uid = 1001]
UserHandler::check() [uid = 1001]   
AuthHandler::check() [uid = 1001]   
handler1.check(1002)开始
RequestHandler::check() [uid = 1002]
UserHandler::check() [uid = 1002]   
handler2.check(1001)开始
AuthHandler::check() [uid = 1001]   
RequestHandler::check() [uid = 1001]
UserHandler::check() [uid = 1001]   
handler2.check(1002)开始
AuthHandler::check() [uid = 1002]
'''
