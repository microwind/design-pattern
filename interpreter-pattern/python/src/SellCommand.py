# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.Command import Command

# 购买命令，操作receiver，实现了抽象命令类
class SellCommand(Command):
    def __init__(self, stockReceiver):
        Command.__init__(self)
        self.stockReceiver = stockReceiver

    # 命令类调用执行者来自行真正的动作
    def execute(self):
        print(self.__class__.__name__ + '::execute() ')
        self.stockReceiver.sell()
