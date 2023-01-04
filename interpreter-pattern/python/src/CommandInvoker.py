# -*- coding: utf-8 -*-
"""
@author: jarry
"""

# 命令调用类，通过关联命令来实行命令的调用
class CommandInvoker:
    def __init__(self):
        self.commandList = []

    # 储存命令
    def take_order(self, command):
        print(
            self.__class__.__name__ + '::takeOrder() ' + command.__class__.__name__
        )
        self.commandList.append(command)

    # 统一执行
    def execute_orders(self):
        print(self.__class__.__name__ + '::executeOrders() ')
        for command in self.commandList:
            command.execute()

        self.commandList = []
