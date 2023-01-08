# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from abc import abstractmethod, ABCMeta


# 定义抽象模板类
class GameTemplate(metaclass=ABCMeta):
    # 抽象方法待子类来实现
    @abstractmethod
    def init(self):
        pass

    @abstractmethod
    def start(self):
        pass

    @abstractmethod
    def end(self):
        pass

    # 可复用的算法流程
    def play(self):
        print(self.__class__.__name__ + '::play()')

        # 初始化游戏
        self.init()

        # 开始游戏
        self.start()

        # 结束游戏
        self.end()
