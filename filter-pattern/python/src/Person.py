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

    def get_name(self):
        return self.name

    def get_gender(self):
        return self.gender

    def get_status(self):
        return self.status

    def to_string(self):
        return 'Person : [ Name : ' + self.get_name(
        ) + ', Gender : ' + self.get_gender(
        ) + ', Marital Status : ' + self.get_status() + ' ]'
