# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.Criteria import Criteria


# 定义Or过滤标准
class OrCriteria(Criteria):

    def __init__(self, criteria, other_criteria):
        Criteria.__init__(self)
        self.criteria = criteria
        self.other_criteria = other_criteria

    def filter(self, persons):
        firstCriteriaItems = self.criteria.filter(persons)
        other_criteriaItems = self.other_criteria.filter(persons)
        for person in other_criteriaItems:
            if person not in firstCriteriaItems:
                firstCriteriaItems.append(person)

        return firstCriteriaItems
