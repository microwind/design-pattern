# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.Expression import Expression

# 构建变量表达式，或者叫终端表达式，其他表达式求值时通过层层追溯最后指向这里
# 变量与执行环境的Key对应，最终会通过key获取传入的值
class VarExpression(Expression):

    def __init__(self, key):
        Expression.__init__(self)
        self.key = key

    # 覆盖表达式，根据key获取变量
    def interpret(self, context):
        return context.get(self.key)