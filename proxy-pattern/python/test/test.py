# -*- coding: utf-8 -*-
"""
@author: jarry
"""
import sys
import os

os_path = os.getcwd()
sys.path.append(os_path)

from src.ProxyImage import ProxyImage


def test():
    '''
    * 代理模式就是用一个类来代理另一个类或几个类的功能，以便隔绝外部客户和内部真实类
    * 这样真实类和调用方之间有一个代理屏障，保证了安全
    * 同时真实的类如果初始化过，就不再初始化，提升了性能
    '''

    # 声明代理类来执行真实类的能力
    image = ProxyImage('001.jpg')

    # 代理类执行真实类的能力
    image.display()

    # 再调用一次，不会重复实例化
    image.display()


if __name__ == '__main__':
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
ProxyImage::display() 001.jpg
RealImage::load_from_disk()  001.jpg
RealImage::display() 001.jpg
ProxyImage::display() 001.jpg
RealImage::display() 001.jpg
'''