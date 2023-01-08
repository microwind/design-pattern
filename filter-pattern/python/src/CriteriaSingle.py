# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.Criteria import Criteria


# 定义子类覆写父类抽象方法
class CriteriaSingle(Criteria):

    def filter(self, persons):
        singlePersons = []
        for person in persons:
            if person.getStatus().upper() == 'SINGLE':
                singlePersons.append(person)

        return singlePersons
