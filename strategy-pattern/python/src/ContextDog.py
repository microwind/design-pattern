# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.Context import Context
from src.StrategyB import StrategyB
class ContextDog(Context):
  def __init__(self,):
    print('ContextDog::setStrategy(StrategyB).')
    self.set_strategy(StrategyB())
