# -*- coding: utf-8 -*-
"""
@author: jarry
"""

# 命令模式真正的执行类，不直接对外，通过command来调用
class StockReceiver:
    def __init__(self, name, num):
        self.name = name
        self.num = num

    def buy(self):
        print(
            self.__class__.__name__ +
            '::buy() [name=' +
            self.name +
            ' num=' +
            str(self.num) +
            ']'
        )

    def sell(self):
        print(
            self.__class__.__name__ +
            '::sell() [name=' +
            self.name +
            ' num=' +
            str(self.num) +
            ']'
        )
