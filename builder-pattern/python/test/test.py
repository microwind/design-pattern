# -*- coding: utf-8 -*-
"""
@author: jarry
"""
import sys
import os
os_path = os.getcwd()
sys.path.append(os_path)

from src.Application import Application
from src.Director import Director
from src.PhoneBuilder import PhoneBuilder
from src.ManualBuilder import ManualBuilder

def test():
  Application.makeIPhone()

  Application.makeHuaweiPhone()

  # *********************** 分割线 ******************************************/

  # 声明指挥者
  director = Director()
  # 创建手机
  phoneBuilder = PhoneBuilder()
  director.buildMiPhone(phoneBuilder)
  miPhone = phoneBuilder.getProduct()
  print('miPhone:' + miPhone.getName() + ' | ', miPhone)
  # 创建手册
  manualBuilder = ManualBuilder()
  director.buildMiPhone(manualBuilder)
  manual = manualBuilder.getProduct()
  print('manual:' + manual.getName() + ' | ', manual)

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
('iPhone:iPhone | ', <src.Phone.Phone instance at 0x106432680>)
('manual:iPhone | ', <src.Manual.Manual instance at 0x106432710>)
('huaweiPhone:HuaweiPhone | ', <src.Phone.Phone instance at 0x106432680>)
('manual:HuaweiPhone | ', <src.Manual.Manual instance at 0x1064325f0>)
('miPhone:MiPhone | ', <src.Phone.Phone instance at 0x106432680>)
('manual:MiPhone | ', <src.Manual.Manual instance at 0x106432710>)


jarry@jarrys-MacBook-Pro python % python3 -V
Python 3.8.10
jarry@jarrys-MacBook-Pro python % python3 test/test.py
test/test.py
test start:
iPhone:iPhone |  <src.Phone.Phone object at 0x10ff38280>
manual:iPhone |  <src.Manual.Manual object at 0x10ff38b80>
huaweiPhone:HuaweiPhone |  <src.Phone.Phone object at 0x10ff38310>
manual:HuaweiPhone |  <src.Manual.Manual object at 0x10ff5a070>
miPhone:MiPhone |  <src.Phone.Phone object at 0x10ff38310>
manual:MiPhone |  <src.Manual.Manual object at 0x10fecc7f0>
'''