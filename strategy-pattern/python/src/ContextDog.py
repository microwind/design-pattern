# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from Context import Context
from StrategyB import StrategyB
class ContextDog(Context):
  def __init__(self,):
    print('ContextDog::setStrategy(StrategyB).')
    self.set_strategy(StrategyB())
