# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.OrganizationComponent import OrganizationComponent


# 实现部件的叶子节点，叶子节点不能再含有子节点
class EmployeeLeaf(OrganizationComponent):
    def __init__(self, name):
        # OrganizationComponent.__init__(self, name)
        super(EmployeeLeaf, self).__init__(name)

    # 叶子节点不能再增加内容
    def add(self):
        print("Leaf can't add.")

    # 叶子节点没有移除内容
    def remove(self):
        print("Leaf can't remove.")

    # 叶子节点无获取子节点

    def get_child(self):
        print("Leaf can't getChild.")
        return None

    def operation(self):
        print(self.__class__.__name__ + ' EmployeeLeaf::operation() ' + self.name)
