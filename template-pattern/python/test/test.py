# -*- coding: utf-8 -*-
"""
@author: jarry
"""

import sys
import os

os_path = os.getcwd()
sys.path.append(os_path)

from src.Football import Football
from src.Basketball import Basketball
from src.Tennis import Tennis


def test():
    '''
    * 模板方法模式就是当子类具备类似行为的时候，让子类共用一套流程
    * 创建一个公共模板，确定公用流程和操作动作，子类覆盖具体的动作
    '''
    football = Football()
    football.play()

    print('===')
    basketball = Basketball()
    basketball.play()

    print('===')
    tennis = Tennis()
    tennis.play()


if __name__ == '__main__':
    print(__file__)
    print("test start:")
    test()
'''
jarry@jarrys-MacBook-Pro python % python3 test/test.py
test/test.py
test start:
Football::play()
Football::init() [Football Game Initialized! Start playing.]
Football::start() [Football Game Started. Enjoy the game!]
Football::end() [Football Game Finished!]
===
Basketball::play()
Basketball::init() [Basketball Game Initialized! Start playing.]
Basketball::start() [Basketball Game Started. Enjoy the game!]
Basketball::end() [Basketball Game Finished!]
===
Tennis::play()
Tennis::init() [Tennis Game Initialized! Start playing.]
Tennis::start() [Tennis Game Started. Enjoy the game!]
Tennis::end() [Tennis Game Finished!]
'''