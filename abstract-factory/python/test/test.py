# -*- coding: utf-8 -*-
"""
@author: jarry
"""
import sys
import os
os_path = os.getcwd()
sys.path.append(os_path)

# 把当前文件所在文件夹的父文件夹路径加入到PYTHONPATH
# sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


from src.VehicleFactory import VehicleFactory
from src.VehicleFactory import VehicleType
from src.FactoryCreator import FactoryCreator

def test():
  vehicle_factory = FactoryCreator.get_factory('vehicle')

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


  # *********************** 分割线 ******************************************/

  # 声明商店工厂
  shop_factory = FactoryCreator.get_factory('shop')
  # 从商店工厂获取商店对象
  shop = shop_factory.get_shop('SupermarketShop')
  # 调用商店的方法
  shop.greetings()

  # *********************** 分割线 ******************************************/

  # 再声明一个商店工厂
  shop_factory2 = FactoryCreator.get_factory('shop')
  direct_sale_shop = shop_factory2.get_shop('DirectSaleShop')
  direct_sale_shop.greetings()
  direct_sale_shop.welcome()

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
AbstractFactory init.
Bus::run()
Car::run()
Motorcycle::run()
Van::run()
ShopFactory init
Shop init
SupermarketShop::greetings
ShopFactory init
Shop init
DirectSaleShop::greetings
Shop::Welcome
'''

'''
jarry@jarrys-MacBook-Pro python % python3 -V
Python 3.8.10
jarry@jarrys-MacBook-Pro python % python3 test/test.py
test/test.py
test start:
AbstractFactory init.
Bus::run()
Car::run()
Motorcycle::run()
Van::run()
ShopFactory init
Shop init
SupermarketShop::greetings
ShopFactory init
Shop init
DirectSaleShop::greetings
Shop::Welcome
'''