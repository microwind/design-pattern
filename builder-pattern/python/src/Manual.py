# -*- coding: utf-8 -*-
"""
@author: jarry
"""

class Manual():
  name = 'ManualName'
  __name__ = 'Manual'
  screen = [0, 0]
  gpuType = 0

  def __init__(self):
    pass

  def setName(self, name):
    self.name = name

  def getName(self):
    return self.name

  def setScreen(self, screen):
    self.screen = screen

  def getScreen(self):
    return self.screen

  def setGpuType(self, type):
    self.gpuType = type

  def getGpuType(self):
    return self.gpuType