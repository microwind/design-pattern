# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from abc import abstractmethod, ABCMeta

# 命令抽象接口，是否抽象可选
class Command(metaclass=ABCMeta):
    @abstractmethod
    def execute(sefl):
        pass
