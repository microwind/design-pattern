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
    '''
    * 享元模式就是将已经声明过的实例或数据保存在内存里，需要使用时则取出来，无需再次实例化和声明。
    * 通过共享多个对象所共有的相同状态，以达到节省开销的目的。
    * 享元模式分为内部状态和外部状态，内部状态基于享元对象共享，外部状态则外部传入或使用非享元类。
    '''
    # 假设有钢琴和吉他，钢琴使用者很多需要共享实例，而吉他每次创建新实例

    # 2个一样名称的为共享对象，只创建1个实例，后面的返回缓存实例
    factory1 = FlyweightFactory.get_factory('piano1')
    # piano1已经声明过了，同名则共享前面的实例
    factory2 = FlyweightFactory.get_factory('piano1')
    factory3 = FlyweightFactory.get_factory('piano2')
    factory4 = FlyweightFactory.get_factory('piano2')

    factory1.operate('factory1')
    factory2.operate('factory2')
    factory3.operate('factory3')
    factory4.operate('factory4')

    # 查看一共多少个对象
    # for entry in FlyweightFactory.pool:
    #     print('保存的对象:' + entry)

    for flyweight in FlyweightFactory.pool.values():
        print('享元对象:' + flyweight.get_name())

    # 无需共享的，名字一样也是多个对象
    factory5 = UnsharedConcreteFlyweight('guitar1')
    factory6 = UnsharedConcreteFlyweight('guitar1')
    factory5.operate('factory5')
    factory6.operate('factory6')


if __name__ == '__main__':
    print(__file__)
    print("test start:")
    test()
'''
jarry@jarrys-MacBook-Pro python % python test/test.py
test start:
ConcreteFlyweight::__init__(name) [创建具体享元piano1]
FlyweightFactory::get_factory(name) [成功获取具体享元piano1]
ConcreteFlyweight::__init__(name) [创建具体享元piano2]
FlyweightFactory::get_factory(name) [成功获取具体享元piano2]
ConcreteFlyweight::operate() [piano1,piano,factory1]
ConcreteFlyweight::operate() [piano1,piano,factory2]
ConcreteFlyweight::operate() [piano2,piano,factory3]
ConcreteFlyweight::operate() [piano2,piano,factory4]
享元对象:piano1
享元对象:piano2
UnsharedConcreteFlyweight::__init__(name) [创建非共享对象guitar1]
UnsharedConcreteFlyweight::__init__(name) [创建非共享对象guitar1]
UnsharedConcreteFlyweight::operate() [guitar1,guitar,factory5]
UnsharedConcreteFlyweight::operate() [guitar1,guitar,factory6]
'''
