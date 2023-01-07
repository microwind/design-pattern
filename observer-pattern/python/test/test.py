# -*- coding: utf-8 -*-
"""
@author: jarry
"""

import sys
import os

os_path = os.getcwd()
sys.path.append(os_path)

from src.ConcreteSubject import ConcreteSubject
from src.ConcreteObserver import ConcreteObserver
from src.ConcreteObserver2 import ConcreteObserver2


def test():
    '''
    * 观察者模式应用非常广泛，主要是观察者提前绑定到发布者
    * 当发布者发布消息时，批量广播通知，而无需逐一通知
    * 观察者监听到消息后自己决定采取哪一种行为
    '''

    # 定义一个主题，也就是发布者
    concrete_subject = ConcreteSubject('subject1')
    # 再声明观察者，通过构造器注册到主题上
    observer1 = ConcreteObserver(concrete_subject, 'observer1')
    # 也可以单独给主题注册一个新的观察者
    observer2 = ConcreteObserver2('observer2')
    concrete_subject.register(observer2)
    # 可以移除观察者对象
    # concrete_subject.remove(observer1)

    # 主题开始发布新通知，各观察者自动更新
    concrete_subject.notify('hello, this is broadcast.')


if __name__ == '__main__':
    print(__file__)
    print("test start:")
    test()
'''
jarry@jarrys-MacBook-Pro python % python -V
Python 2.7.16

jarry@jarrys-MacBook-Pro python % python test/test.py
test start:
ConcreteSubject::register() [observer = ConcreteObserver]
ConcreteSubject::register() [observer = ConcreteObserver2]
ConcreteSubject::notify() [content = hello, this is broadcast.]
ConcreteObserver::update() [subject.name = subject1 content = hello, this is broadcast.]
ConcreteObserver2::update() [content = hello, this is broadcast.]
'''