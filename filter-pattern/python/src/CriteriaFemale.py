# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.Criteria import Criteria


# 根据标准接口实现的过滤
class CriteriaFemale(Criteria):

    def filter(self, persons):
        female_persons = []
        for person in persons:
            if person.get_gender().upper() == 'FEMALE':
                female_persons.append(person)

        return female_persons
