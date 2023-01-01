# -*- coding: utf-8 -*-
"""
@author: jarry
"""
# 网络模块


class NetworkModule:
    def request(self):
        print(self.__class__.__name__ + '::request() 远程读取。')
