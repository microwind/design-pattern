# -*- coding: utf-8 -*-
"""
@author: jarry
"""

class Singleton(object):
  instance = None

  def __init__(self):
    raise SyntaxError('can not instance, please use get_instance')

  @staticmethod
  def get_instance(name):
    if Singleton.instance is None:
      Singleton.instance = object.__new__(Singleton)
      Singleton.name = name
    return Singleton.instance

  def run(self):
    print('Singleton::run()', self.name)