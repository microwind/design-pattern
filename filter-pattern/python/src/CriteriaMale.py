# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.Criteria import Criteria


# 根据标准接口实现的过滤
class CriteriaMale(Criteria):

    def filter(self, persons):
        malePersons = []
        for person in persons:
            if person.get_gender().upper() == 'MALE':
                malePersons.append(person)

        return malePersons
