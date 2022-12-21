# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from threading import Lock, Thread

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


class SingletonSafe(metaclass=SingletonMeta):
    value: str = None

    def __init__(self, value: str) -> None:
        self.value = value

    def run(self):
      print('SingletonSafe::run()', self.value)