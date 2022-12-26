# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.Image import Image
from src.Image import Image


# 真实类实现基础接口
class RealImage(Image):

    real_image = None
    file_name = None

    def __init__(self, file_name):
        Image.__init__(self)
        self.file_name = file_name
        self.load_from_disk(file_name)

    def display(self):
        print('RealImage::display() ' + self.file_name)

    # 这个方法只是内部使用
    def load_from_disk(self, file_name):
        print('RealImage::load_from_disk()  ' + file_name)
