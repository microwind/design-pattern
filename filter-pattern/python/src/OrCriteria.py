# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.Criteria import Criteria


# 定义Or过滤标准
class OrCriteria(Criteria):

    def __init__(self, criteria, otherCriteria):
        Criteria.__init__(self)
        self.criteria = criteria
        self.otherCriteria = otherCriteria

    def filter(self, persons):
        firstCriteriaItems = self.criteria.filter(persons)
        otherCriteriaItems = self.otherCriteria.filter(persons)
        for person in otherCriteriaItems:
            if person not in firstCriteriaItems:
                firstCriteriaItems.append(person)

        return firstCriteriaItems
