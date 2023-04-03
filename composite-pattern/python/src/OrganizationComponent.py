# -*- coding: utf-8 -*-
"""
@author: jarry
"""
# 定义部件接口或抽象类，分支和叶子节点遵循该类约定


class OrganizationComponent:
    def __init__(self, name):
        self.set_name(name)

    def add(self, component):
        self.children.append(component)

    def remove(self, component):
        for i in range(len(self.children)):
            # 根据名称或直接删除成员
            if (self.children[i] == component):
            # if (self.children[i].get_name() == component.get_name()):
                del self.children[i]
                break

    def get_child(self, index):
        return self.children[index]

    def operation(self):
        print(self.__class__.__name__ + '::operation() ' + self.name)
        for component in self.children:
            component.operation()

    def get_name(self):
        return self.name

    def set_name(self, name):
        self.name = name
