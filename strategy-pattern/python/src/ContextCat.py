# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from Context import Context
from StrategyC import StrategyC
class ContextCat(Context):
  def __init__(self,):
    print('ContextCat::setStrategy(StrategyC).')
    self.set_strategy(StrategyC())
