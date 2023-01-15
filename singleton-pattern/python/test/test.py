# -*- coding: utf-8 -*-
"""
@author: jarry
"""
import sys
import os
os_path = os.getcwd()
sys.path.append(os_path)

from src.SingletonStatic import SingletonStatic
from src.SingletonSimple import SingletonSimple, SingletonSimpleClass
# 这里导入的是基于元类的单例类
from src.SingletonType import SingletonTypeClass
from src.SingletonSafe import SingletonSafe

def test():
  '''
  * 单例模式就是一个类只创建一个实例，以便节省开销和保证统一
  * 对于多线程语言需要注意线程安全和性能之间取得一个平衡
  '''

  singleton1 = SingletonStatic.get_instance('singleton1')
  # 获得的是同一个实例，名称相同
  singleton1.run()
  singleton2 = SingletonStatic.get_instance('singleton2')
  singleton2.run()

  # *********************** 分割线 ******************************************/

  singleton1 = SingletonSimpleClass('SingletonSimple1')
  # 获得的是同一个实例，名称相同
  singleton2 = SingletonSimpleClass('SingletonSimple2')
  singleton1.run()
  singleton2.run()

  # *********************** 分割线 ******************************************/

  singleton1 = SingletonTypeClass('SingletonTypeClass1')
  # 获得的是同一个实例，名称相同
  singleton2 = SingletonTypeClass('SingletonTypeClass2')
  singleton1.run()
  singleton2.run()

  # *********************** 分割线 ******************************************/
  # 适用python3
  singleton1 = SingletonSafe('SingletonSafe1')
  # 获得的是同一个实例，名称相同
  singleton2 = SingletonSafe('SingletonSafe2')
  singleton1.run()
  singleton2.run()


if __name__=='__main__':
  print(__file__)
  print("test start:")
  test()

'''
jarry@jarrys-MacBook-Pro python % python3 test/test.py
test/test.py
test start:
SingletonStatic::run() singleton1
SingletonStatic::run() singleton1
SingletonSimple::run() SingletonSimple1
SingletonSimple::run() SingletonSimple1
SingletonTypeClass::run() SingletonTypeClass1
SingletonTypeClass::run() SingletonTypeClass1
SingletonSafe::run() SingletonSafe1
SingletonSafe::run() SingletonSafe1
'''