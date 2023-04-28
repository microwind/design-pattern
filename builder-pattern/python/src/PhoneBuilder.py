# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.Builder import Builder
from src.Phone import Phone

class PhoneBuilder(Builder):
  phone = None

  def __init__(self):
    pass

  def reset(self):
    self.phone = Phone()

  def setName(self, name):
    self.phone.setName(name)
    return self

  def setScreen(self, screen):
    self.phone.setScreen(screen)
    return self

  def setGPU(self, no):
    self.phone.setGpuType(no)
    return self

  def getProduct(self):
    return self.phone