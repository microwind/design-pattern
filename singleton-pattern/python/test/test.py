# -*- coding: utf-8 -*-
"""
@author: jarry
"""
import sys
import os
os_path = os.getcwd()
sys.path.append(os_path)

from src.Singleton import Singleton
from src.SingletonSimple import SingletonSimple
# 线程安全
# from src.SingletonSafe import SingletonSafe

def test():
  '''
  * 单例模式就是一个类只创建一个实例，以便节省开销和保证统一
  * 对于多线程语言需要注意线程安全和性能之间取得一个平衡
  '''

  singleton1 = Singleton.get_instance('singleton1')
  singleton1.run()

  singleton2 = Singleton.get_instance('singleton2')
  singleton2.run()

  # *********************** 分割线 ******************************************/

  singleton1 = SingletonSimple.get_instance('SingletonSimple1')
  singleton1.run()

  singleton2 = SingletonSimple.get_instance('SingletonSimple2')
  singleton2.run()

  # *********************** 分割线 ******************************************/
  # 适用python3
  '''
  singleton1 = SingletonSafe('SingletonSimple1')
  singleton1.run()

  singleton2 = SingletonSafe('SingletonSimple2')
  singleton2.run()
  '''

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
('Singleton::run()', 'singleton1')
('Singleton::run()', 'singleton1')
('SingletonSimple::run()', 'SingletonSimple1')
('SingletonSimple::run()', 'SingletonSimple1')


jarry@jarrys-MacBook-Pro python % python3 -V
Python 3.8.10
jarry@jarrys-MacBook-Pro python % python3 test/test.py
test/test.py
test start:
Singleton::run() singleton1
Singleton::run() singleton1
SingletonSimple::run() SingletonSimple1
SingletonSimple::run() SingletonSimple1
SingletonSafe::run() SingletonSimple1
SingletonSafe::run() SingletonSimple1
'''