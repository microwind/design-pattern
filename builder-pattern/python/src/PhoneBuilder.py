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

  def setScreen(self, screen):
    self.phone.setScreen(screen)

  def setGPU(self, no):
    self.phone.setGpuType(no)

  def getProduct(self):
    return self.phone