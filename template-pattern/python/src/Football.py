# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.GameTemplate import GameTemplate


# 定义子类覆写父类抽象方法
class Football(GameTemplate):

    def init(self):
        print('Football::init() [Football Game Initialized! Start playing.]')

    def start(self):
        print('Football::start() [Football Game Started. Enjoy the game!]')

    def end(self):
        print('Football::end() [Football Game Finished!]')
