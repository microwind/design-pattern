# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.Bus import Bus
from src.Car import Car
from src.Motorcycle import Motorcycle
from src.Van import Van

from enum import Enum

class VehicleType(Enum):
  BUS = 1
  CAR = 2
  MOTORCYCLE = 3
  VAN = 4

class VehicleFactory:
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
