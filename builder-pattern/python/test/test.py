# -*- coding: utf-8 -*-
"""
@author: jarry
"""
import sys
import os
os_path = os.getcwd()
sys.path.append(os_path)

import json
from src.Application import Application
from src.Director import Director
from src.PhoneBuilder import PhoneBuilder
from src.ManualBuilder import ManualBuilder

def test():
  '''
   * 建造者模式是使用多个简单的对象一步一步构建出一个复杂的对象来。
   * 分为主管类和建造者类，主管类负责具体指挥调度，建造负责具体实施。
   * 主管类通过一步一步调用各种建造者实现复杂对象。
  '''

  Application.makeIPhone()

  Application.makeHuaweiPhone()

  # *********************** 分割线 ******************************************/

  # 声明指挥者
  director = Director()
  # 创建手机
  phoneBuilder = PhoneBuilder()
  director.buildMiPhone(phoneBuilder)
  miPhone = phoneBuilder.getProduct()
  print('miPhone:' + miPhone.getName() + ' | ', json.dumps(miPhone.__dict__))
  # 创建手册
  manualBuilder = ManualBuilder()
  director.buildMiPhone(manualBuilder)
  manual = manualBuilder.getProduct()
  print('manual:' + manual.getName() + ' | ', json.dumps(manual.__dict__))

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
('iPhone:iPhone | ', '{"screen": [120, 500], "name": "iPhone", "gpuType": 100}')
('manual:iPhone | ', '{"screen": [120, 500], "name": "iPhone", "gpuType": 100}')
('huaweiPhone:HuaweiPhone | ', '{"screen": [140, 600], "name": "HuaweiPhone", "gpuType": 102}')
('manual:HuaweiPhone | ', '{"screen": [140, 600], "name": "HuaweiPhone", "gpuType": 102}')
('miPhone:MiPhone | ', '{"screen": [130, 550], "name": "MiPhone", "gpuType": 103}')
('manual:MiPhone | ', '{"screen": [130, 550], "name": "MiPhone", "gpuType": 103}')


jarry@jarrys-MacBook-Pro python % python3 -V
Python 3.8.10
jarry@jarrys-MacBook-Pro python % python3 test/test.py
test/test.py
test start:
iPhone:iPhone |  {"name": "iPhone", "screen": [120, 500], "gpuType": 100}
manual:iPhone |  {"name": "iPhone", "screen": [120, 500], "gpuType": 100}
huaweiPhone:HuaweiPhone |  {"name": "HuaweiPhone", "screen": [140, 600], "gpuType": 102}
manual:HuaweiPhone |  {"name": "HuaweiPhone", "screen": [140, 600], "gpuType": 102}
miPhone:MiPhone |  {"name": "MiPhone", "screen": [130, 550], "gpuType": 103}
manual:MiPhone |  {"name": "MiPhone", "screen": [130, 550], "gpuType": 103}
'''