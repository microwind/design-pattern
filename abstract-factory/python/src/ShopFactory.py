# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.shop.AgencyShop import AgencyShop
from src.shop.DirectSaleShop import DirectSaleShop
from src.shop.SupermarketShop import SupermarketShop
from src.AbstractFactory import AbstractFactory

class ShopFactory(AbstractFactory):
  def __init__(self,):
    print("ShopFactory init")

  def get_shop(self, type):
    if type == 'AgencyShop':
      return AgencyShop()
    elif type == 'DirectSaleShop':
      return DirectSaleShop()
    elif type == 'SupermarketShop':
      return SupermarketShop()
    else:
      return None

  # 如果是继承抽象类则需要实现抽象类全部方法
  def get_vehicle(self, type):
    return None