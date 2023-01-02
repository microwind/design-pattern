# -*- coding: utf-8 -*-
"""
@author: jarry
"""

import sys
import os

os_path = os.getcwd()
sys.path.append(os_path)

from src.StockReceiver import StockReceiver
from src.BuyCommand import BuyCommand
from src.SellCommand import SellCommand
from src.CommandInvoker import CommandInvoker

def test():
    '''
    * 命令模式是客户端通过一个命令执行者invoker，去执行某个命令command
    * 而命令则调用了业务类receiver的具体动作，从而完成真正的执行
    '''

    # 先声明一个被操作对象，也就是接收者
    stock1 = StockReceiver('Apple', 200)

    # 再声明具体的命令
    buy_command = BuyCommand(stock1)
    sell_command = SellCommand(stock1)

    # 最后声明调用者，由调用者来执行具体命令
    invoker = CommandInvoker()
    invoker.take_order(buy_command)
    invoker.take_order(sell_command)
    invoker.execute_orders()

    # 再执行一只股票
    stock2 = StockReceiver('Google', 100)
    sell_command2 = BuyCommand(stock2)
    invoker.take_order(sell_command2)
    invoker.execute_orders()


if __name__ == '__main__':
    print(__file__)
    print("test start:")
    test()
'''
jarry@jarrys-MacBook-Pro python % python -V
Python 3.11.1

jarry@jarrys-MacBook-Pro python % python test/test.py
test start:
CommandInvoker::takeOrder() BuyCommand
CommandInvoker::takeOrder() SellCommand
CommandInvoker::executeOrders()
BuyCommand::execute()
StockReceiver::buy() [name=Apple num=200]
SellCommand::execute()
StockReceiver::sell() [name=Apple num=200]
CommandInvoker::takeOrder() BuyCommand
CommandInvoker::executeOrders()
BuyCommand::execute()
StockReceiver::buy() [name=Google num=100]
'''
