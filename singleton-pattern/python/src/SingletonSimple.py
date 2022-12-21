# -*- coding: utf-8 -*-
"""
@author: jarry
"""

class SingletonSimple():
  instance = None

  def __init__(self, name):
    self.name = name
    pass

  @staticmethod
  def get_instance(name):
    if SingletonSimple.instance is None:
      SingletonSimple.instance = SingletonSimple(name)
      SingletonSimple.name = name
    return SingletonSimple.instance

  def run(self):
    print('SingletonSimple::run()', self.name)