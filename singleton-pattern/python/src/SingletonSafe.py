# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from threading import Lock, Thread


# 加锁的基于元类的单例模式，基于元类type创建的加强版
class SingletonMeta(type):
    # 线程安全单例模式，适用python3
    _instances = {}

    _lock: Lock = Lock()

    def __call__(cls, *args, **kwargs):
        with cls._lock:
            if cls not in cls._instances:
                instance = super().__call__(*args, **kwargs)
                cls._instances[cls] = instance
        return cls._instances[cls]

# 继承SingletonMeta就是单例
class SingletonSafe(metaclass=SingletonMeta):
    name: str = None

    def __init__(self, name: str) -> None:
        self.name = name

    def run(self):
        print('SingletonSafe::run()', self.name)
