# -*- coding: utf-8 -*-
"""
@author: jarry
"""

# 通过静态方法来实例化对象，当实例化过后就不再生成
class SingletonStatic(object):
  instance = None

  def __init__(self):
    pass
    # raise SyntaxError('can not instance, please use get_instance')

  @staticmethod
  def get_instance(name):
    if SingletonStatic.instance is None:
      # 当实例不存在时用__new__来创建
      SingletonStatic.instance = object.__new__(SingletonStatic)
      # 或者直接实例化对象
      # SingletonStatic.instance = SingletonStatic()
      SingletonStatic.name = name
    return SingletonStatic.instance

  def run(self):
    print('SingletonStatic::run()', self.name)