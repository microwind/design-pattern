# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from abc import abstractmethod, ABCMeta

# 访问者Visitor抽象接口，定义visit方法，传递元素对象
class Visitor(metaclass=ABCMeta):

    # python不支持函数重载，参数没有区分类型
    # 如要区分，则可以通过不同函数名来实现
    @abstractmethod
    def visit(self, concreteElement):
        pass

    def get_name(self):
        pass
