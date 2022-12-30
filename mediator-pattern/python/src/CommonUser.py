# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.AbstractUser import AbstractUser

# 继承基础类的普通用户


class CommonUser(AbstractUser):
    def __init__(self, name):
        AbstractUser.__init__(self, name)
