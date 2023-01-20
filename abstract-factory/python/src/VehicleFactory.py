# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.vehicle.Bus import Bus
from src.vehicle.Car import Car
from src.vehicle.Motorcycle import Motorcycle
from src.vehicle.Van import Van
from src.AbstractFactory import AbstractFactory
from enum import Enum

class VehicleType(Enum):
  BUS = 1
  CAR = 2
  MOTORCYCLE = 3
  VAN = 4

# 具体工厂类，实现抽象父类工厂接口
class VehicleFactory(AbstractFactory):
  # def __init__(self,):
    # print("VehicleFactory init")

  def get_vehicle(self, type):
    if type == VehicleType.BUS:
      return Bus()
    elif type == VehicleType.CAR:
      return Car()
    elif type == VehicleType.MOTORCYCLE:
      return Motorcycle()
    elif type == VehicleType.VAN:
      return Van()
    else:
      return None

  # 如果是抽象类则需要将全部方法复写一遍
  def get_shop(self, type):
    return None
