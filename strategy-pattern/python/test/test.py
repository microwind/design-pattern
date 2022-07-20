# -*- coding: utf-8 -*-
"""
@author: jarry
"""
import sys
import os
os_path = os.getcwd()
sys.path.append(os_path)

from src.StrategyA import StrategyA
from src.ContextDog import ContextDog
from src.ContextCat import ContextCat

def test():
  # 实例化某个内容，策略已经绑定上
  context_cat = ContextCat()
  context_cat.action()

  # 重新设置策略
  print("reset contextCat'strategy to StrategyA.")
  context_cat.set_strategy(StrategyA())
  context_cat.action()

  # 实例化某个内容，策略已经绑定上
  context_dog = ContextDog()
  context_dog.action()

if __name__=='__main__':
  print(__file__)
  print("test start:")
  test()

'''
jarry@jarrys-MacBook-Pro python % python -V
Python 2.7.16
jarry@jarrys-MacBook-Pro python % python test/test.py 
test/test.py
test start:
ContextCat::setStrategy(StrategyC).
StrategyC::run()
reset contextCat'strategy to StrategyA.
StrategyA::run()
ContextDog::setStrategy(StrategyB).
StrategyB::run()
'''