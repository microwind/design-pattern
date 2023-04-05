# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.Criteria import Criteria


# 定义And过滤标准
class AndCriteria(Criteria):

    def __init__(self, criteria, other_criteria):
        Criteria.__init__(self)
        self.criteria = criteria
        self.other_criteria = other_criteria

    def filter(self, persons):
        first_criteria_persons = self.criteria.filter(persons)
        return self.other_criteria.filter(first_criteria_persons)
