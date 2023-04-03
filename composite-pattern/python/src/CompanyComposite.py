# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.OrganizationComponent import OrganizationComponent

# 实现部件的树枝构件1


class CompanyComposite(OrganizationComponent):
    def __init__(self, name):
        OrganizationComponent.__init__(self, name)
        self.children = []

    def operation(self):
        print(self.__class__.__name__ + '::operation() prepare')
        # python2支持的父类调用方式
        OrganizationComponent.operation(self)
        # python3支持的父类调用方式
        # super().operation()
