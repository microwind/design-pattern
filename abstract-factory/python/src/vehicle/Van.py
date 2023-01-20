# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.vehicle.Vehicle import Vehicle

# 具体产品类，实现或继承通用产品接口
class Van(Vehicle):
  def run(self):
    print("Van::run()")