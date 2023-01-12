# -*- coding: utf-8 -*-
"""
@author: jarry
"""
import sys
import os
os_path = os.getcwd()
sys.path.append(os_path)

from src.VehicleFactory import VehicleFactory
from src.VehicleFactory import VehicleType

def test():
  '''
   * 工厂模式由工厂类提供统一的创建对象的方法，省去直接new，而是通过统一方法来创建。
   * 这样的好处就是让对象创建和调用解耦，便于在创建对象时统一干预。
  '''
  vehicle_factory = VehicleFactory()

  # 获取Bus对象，并调用它的 run 方法
  bus = vehicle_factory.get_vehicle(VehicleType.BUS)
  bus.run()

  # 获取Car对象，并调用它的 run 方法
  car = vehicle_factory.get_vehicle(VehicleType.CAR)
  car.run()

  # 获取Motorcycle对象，并调用它的 run 方法
  motorcycle = vehicle_factory.get_vehicle(VehicleType.MOTORCYCLE)
  motorcycle.run()

  # 获取Motorcycle对象，并调用它的 run 方法
  van = vehicle_factory.get_vehicle(VehicleType.VAN)
  van.run()

if __name__=='__main__':
  print(__file__)
  print("test start:")
  test()

'''
jarry@jarrys-MacBook-Pro python % python -V
Python 2.7.16
jarry@jarrys-MacBook-Pro python % python test/test.py 
test/test.py
test start:
Bus::run()
Car::run()
Motorcycle::run()
Van::run()
'''