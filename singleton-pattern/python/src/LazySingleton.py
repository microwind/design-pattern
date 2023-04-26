# -*- coding: utf-8 -*-
"""
@author: jarry
"""

# 通过静态方法来实例化对象，当实例化过后就不再生成，存在线程安全问题
class LazySingleton(object):
  instance = None

  def __init__(self):
    pass
    # raise SyntaxError('can not instance, please use get_instance')

  @staticmethod
  def get_instance(name):
    if LazySingleton.instance is None:
      # 当实例不存在时用__new__来创建
      LazySingleton.instance = object.__new__(LazySingleton)
      # 或者直接实例化对象
      # LazySingleton.instance = LazySingleton()
      LazySingleton.name = name
    return LazySingleton.instance

  def run(self):
    print('LazySingleton::run()', self.name)