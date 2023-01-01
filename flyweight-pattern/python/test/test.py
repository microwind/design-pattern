# -*- coding: utf-8 -*-
"""
@author: jarry
"""

import sys
import os

os_path = os.getcwd()
sys.path.append(os_path)

from src.FlyweightFactory import FlyweightFactory
from src.UnsharedConcreteFlyweight import UnsharedConcreteFlyweight

def test():
    # 假设有钢琴和吉他，钢琴使用者很多需要共享实例，而吉他每次创建新实例

    # 2个一样名称的共享对象
    factory1 = FlyweightFactory.get_factory('piano1')
    factory2 = FlyweightFactory.get_factory('piano1')
    factory3 = FlyweightFactory.get_factory('piano2')

    factory1.operate('factory1')
    factory2.operate('factory2')
    factory3.operate('factory3')

    # 查看一共多少个对象
    # for entry in FlyweightFactory.pool:
    #     print('保存的对象:' + entry)
        
    for flyweight in FlyweightFactory.pool.values():
        print('保存的对象:' + flyweight.get_name())

    # 无需共享的，名字一样也是多个对象
    factory4 = UnsharedConcreteFlyweight('guitar1')
    factory5 = UnsharedConcreteFlyweight('guitar1')
    factory4.operate('factory4')
    factory5.operate('factory5')


if __name__ == '__main__':
    print(__file__)
    print("test start:")
    test()


'''
jarry@jarrys-MacBook-Pro python % python test/test.py
test start:
ConcreteFlyweight::operate() [piano1,piano,factory1]
ConcreteFlyweight::operate() [piano1,piano,factory2]
ConcreteFlyweight::operate() [piano2,piano,factory3]
保存的对象:piano1
保存的对象:piano2
UnsharedConcreteFlyweight::operate() [guitar1,guitar,factory4]
UnsharedConcreteFlyweight::operate() [guitar1,guitar,factory5]
'''
