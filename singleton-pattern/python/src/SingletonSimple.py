# -*- coding: utf-8 -*-
"""
@author: jarry
"""


# 通过导入时就实例化的方式来获取，
# 这里的名字与模块名区分开，以便导入到其他模块
class SingletonSimple():

    instance = None

    def __init__(self, name):
        self.name = name

    def run(self):
        print('SingletonSimple::run()', self.name)


# 定义全局变量，导入文件时模块的名称空间会被加载到内存
# 利用模块这个特性，只需把相关函数和数据定义在一个模块中，将它导入到其他模块使用就可以达到单例模式的效果。
singleton_simple_instance = None

# 对外提供一个全局函数，用来初始化单例类
def SingletonSimpleClass(name):
    # 引用全局变量
    global singleton_simple_instance
    if singleton_simple_instance is None:
        singleton_simple_instance = SingletonSimple(name)
    return singleton_simple_instance
