# -*- coding: utf-8 -*-
"""
@author: jarry
"""

import sys
import os

os_path = os.getcwd()
sys.path.append(os_path)

from src.ObjectList import ObjectList


def test():
    '''
    * 迭代器模式是给数据容器创建单独的迭代器，用来遍历里面的数据对象
    * 数据容器和迭代器相互关联，外部通过迭代器来访问数据容器
    * 通过这种方式由迭代器类来负责数据遍历，这样可以做到不暴露集合的内部结构
    '''

    i = 0
    objectList = ObjectList()
    objectList.setObjects(['Thomas', 'Merry', 'Jack', 'Tony', 'Jerry', 'Joey'])

    # 循环迭代对象1
    iter = objectList.createIterator()
    while iter.hasNext():
        name = iter.next()
        print('objectList[' + str(i) + '] = ' + name)
        i += 1

    # 循环迭代对象2
    iter2 = objectList.createIterator()
    while (iter2.hasNext()):
        print(iter2.next())


if __name__ == '__main__':
    print(__file__)
    print("test start:")
    test()
'''
# 这里使用了python3，如果是python2去掉abstract即可
jarry@jarrys-MacBook-Pro python % python3 test/test.py
test start:
ObjectList::createIterator() [获取迭代器 ObjectIterator]
objectList[0] = Thomas
objectList[1] = Merry
objectList[2] = Jack
objectList[3] = Tony
objectList[4] = Jerry
objectList[5] = Joey
ObjectList::createIterator() [获取迭代器 ObjectIterator]
Thomas
Merry
Jack
Tony
Jerry
Joey
'''
