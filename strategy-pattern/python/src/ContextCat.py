# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.Context import Context
from src.StrategyC import StrategyC
class ContextCat(Context):
  def __init__(self,):
    print('ContextCat::setStrategy(StrategyC).')
    self.set_strategy(StrategyC())
