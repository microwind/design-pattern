# -*- coding: utf-8 -*-
"""
@author: jarry
"""


# 定义一个实体类，用来过滤的对象
class Person:

    def __init__(self, name, gender, status):
        self.name = name
        self.gender = gender
        self.status = status

    def getName(self):
        return self.name

    def getGender(self):
        return self.gender

    def getStatus(self):
        return self.status
