# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.AbstractFacade import AbstractFacade
from src.FileModule import FileModule
from src.NetworkModule import NetworkModule
from src.EncodeModule import EncodeModule


# 外观模式实现类，是外部调用与内部子系统的衔接层
class Facade():
# 继承抽象类可选
# class Facade(AbstractFacade):
    def __init__(self):
        self.file_module = FileModule()
        self.network_module = NetworkModule()
        self.encode_module = EncodeModule()

    def encoding(self, id):
        print(self.__class__.__name__ + '::encoding() [id=' + str(id) + ']')
        self.network_module.request()
        self.file_module.read_file()
        self.encode_module.encoding()
        self.file_module.save_file()

    def encrypt(self, id):
        print(self.__class__.__name__ + '::encrypt() [id=' + str(id) + ']')
        self.file_module.read_file()
        self.encode_module.encoding()

    def getfile_module(self):
        return self.file_module

    def getnetwork_module(self):
        return self.network_module

    def getencode_module(self):
        return self.encode_module
