# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.GameTemplate import GameTemplate


# 定义子类覆写父类抽象方法
class Basketball(GameTemplate):

    def init(self):
        print(
            'Basketball::init() [Basketball Game Initialized! Start playing.]')

    def start(self):
        print('Basketball::start() [Basketball Game Started. Enjoy the game!]')

    def end(self):
        print('Basketball::end() [Basketball Game Finished!]')
