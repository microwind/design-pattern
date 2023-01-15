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

    # 在调用父类play之前，如果要执行自己的行为，也可以覆盖父类方法
    # 先执行自己的，再调用父类的方法
    def play(self):
        print(self.__class__.__name__ + '::play() [Tennis Game play!]')
        super().play()
