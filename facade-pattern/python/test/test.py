# -*- coding: utf-8 -*-
"""
@author: jarry
"""

import sys
import os

os_path = os.getcwd()
sys.path.append(os_path)

from src.Facade import Facade

def test():
    facade = Facade()
    facade.encoding(123456)
    facade.encrypt(999999)


if __name__ == '__main__':
    print(__file__)
    print("test start:")
    test()


'''
jarry@jarrys-MacBook-Pro python % python -V
Python 3.11.1

jarry@jarrys-MacBook-Pro python % python test/test.py
test start:
Facade::encoding() [id=123456]
NetworkModule::request() 远程读取。
FileModule::read_file() 读取文件。
EncodeModule::encoding() 进行编码处理。
FileModule::save_file() 保存文件。
Facade::encrypt() [id=999999]
FileModule::read_file() 读取文件。
EncodeModule::encoding() 进行编码处理。
'''
