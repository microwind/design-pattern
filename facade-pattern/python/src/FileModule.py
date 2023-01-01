# -*- coding: utf-8 -*-
"""
@author: jarry
"""
# 文件模块


class FileModule:

    def read_file(self):
        print(self.__class__.__name__ + '::read_file() 读取文件。')

    def save_file(self):
        print(self.__class__.__name__ + '::save_file() 保存文件。')
