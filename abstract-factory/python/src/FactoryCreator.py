# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.VehicleFactory import VehicleFactory
from src.ShopFactory import ShopFactory

# 工厂的创建类，根据需求创建具体工厂
class FactoryCreator:
  # def __init__(self,):
    # print("FactoryCreator init")
    
  @staticmethod
  def get_factory(name):
    if name == 'vehicle':
      return VehicleFactory()
    elif name == 'shop':
      return ShopFactory()
    else:
      return None