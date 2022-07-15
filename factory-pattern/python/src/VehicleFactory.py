# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from Bus import Bus
from Car import Car
from Motorcycle import Motorcycle
from Van import Van

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
