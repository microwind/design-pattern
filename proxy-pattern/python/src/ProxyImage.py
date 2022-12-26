# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.Image import Image
from src.RealImage import RealImage


# 代理类也实现了基础接口
class ProxyImage(Image):

    real_image = None
    file_name = None

    def __init__(self, file_name):
        Image.__init__(self)
        self.real_image = None
        self.file_name = file_name

    def display(self):
        print('ProxyImage::display() ' + self.file_name)
        if self.real_image is None:
            self.real_image = RealImage(self.file_name)
        # 代理类调用真实类的方法
        self.real_image.display()
