# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.ConcreteFlyweight import ConcreteFlyweight

# 享元工厂，储存一个对象共享池，已经生成过的对象直接取出
class FlyweightFactory():
    # 静态变量，共享池
    pool = {}

    def __init__(self):
        pass

    # 这里的name可以认为是内部状态，在构造时确定，具有唯一性。
    @staticmethod
    def get_factory(name):
        pool = FlyweightFactory.pool
        flyweight = pool.get(name)
        if flyweight is None:
            # 如果对象不存在则创建新的对象放入到池子里，如果已经存在则复用前面的对象
            flyweight = ConcreteFlyweight(name)
            pool[name] = flyweight
        else:
            print('FlyweightFactory::get_factory(name) [成功获取具体享元' + name + ']')

        return flyweight
