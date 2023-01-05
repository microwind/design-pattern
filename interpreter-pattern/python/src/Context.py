# -*- coding: utf-8 -*-
"""
@author: jarry
"""

# 构建可执行环境上下文
class Context:
  def __init__(self, key, value):
    self.map = dict()
    self.add(key, value)
  
  def __init__(self):
    self.map = dict()

  def add(self, key, value):
    self.map[key] = value
  

  def get(self, key):
    return self.map[key]
  

