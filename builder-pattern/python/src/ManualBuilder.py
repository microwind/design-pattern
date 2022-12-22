# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.Builder import Builder
from src.Manual import Manual

class ManualBuilder(Builder):
  manual = None

  def __init__(self):
    pass

  def reset(self):
    self.manual = Manual()

  def setName(self, name):
    self.manual.setName(name)

  def setScreen(self, screen):
    self.manual.setScreen(screen)

  def setGPU(self, no):
    self.manual.setGpuType(no)

  def getProduct(self):
    return self.manual