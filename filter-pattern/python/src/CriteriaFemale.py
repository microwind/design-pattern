# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.Criteria import Criteria


# 根据标准接口实现的过滤
class CriteriaFemale(Criteria):

    def filter(self, persons):
        femalePersons = []
        for person in persons:
            if person.getGender().upper() == 'FEMALE':
                femalePersons.append(person)

        return femalePersons
