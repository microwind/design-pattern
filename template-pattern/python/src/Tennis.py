# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.GameTemplate import GameTemplate


# 定义子类覆写父类抽象方法
class Tennis(GameTemplate):

    def init(self):
        print('Tennis::init() [Tennis Game Initialized! Start playing.]')

    def start(self):
        print('Tennis::start() [Tennis Game Started. Enjoy the game!]')

    def end(self):
        print('Tennis::end() [Tennis Game Finished!]')
