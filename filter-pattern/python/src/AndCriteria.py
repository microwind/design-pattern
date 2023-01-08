# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.Criteria import Criteria


# 定义And过滤标准
class AndCriteria(Criteria):

    def __init__(self, criteria, otherCriteria):
        Criteria.__init__(self)
        self.criteria = criteria
        self.otherCriteria = otherCriteria

    def filter(self, persons):
        firstCriteriaPersons = self.criteria.filter(persons)
        return self.otherCriteria.filter(firstCriteriaPersons)
