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
    '''
    * 外观模式就是在外层添加一个访问接口类，客户通过这统一访问接口来访问这些复杂子类。
    * 外观模式与适配器模式比较像，都是提供一个高层访问接口，隔绝外部客户与内部子类。
    * 所不同是外观模式后面的类无需实现相同接口，只是把各种调用整合简化，而适配器需要是同一系列类，为的是解决接口不兼容。
    * 这里声明外观类，外观类的方法里影藏了很多子类的调用。
    '''

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
