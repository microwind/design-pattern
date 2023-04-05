# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.Criteria import Criteria


# 根据标准接口实现的过滤
class CriteriaMale(Criteria):

    def filter(self, persons):
        male_persons = []
        for person in persons:
            if person.get_gender().upper() == 'MALE':
                male_persons.append(person)

        return male_persons
