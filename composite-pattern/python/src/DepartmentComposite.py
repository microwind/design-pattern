# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.OrganizationComponent import OrganizationComponent

# 实现部件的树枝构件2
class DepartmentComposite(OrganizationComponent):
    def __init__(self, name):
        OrganizationComponent.__init__(self, name)
        self.children = []
