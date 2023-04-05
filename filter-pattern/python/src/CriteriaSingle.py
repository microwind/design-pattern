# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.Criteria import Criteria


# 定义子类覆写父类抽象方法
class CriteriaSingle(Criteria):

    def filter(self, persons):
        single_persons = []
        for person in persons:
            if person.get_status().upper() == 'SINGLE':
                single_persons.append(person)

        return single_persons
