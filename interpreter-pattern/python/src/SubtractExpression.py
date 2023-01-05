# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.Expression import Expression


# 具体表达式，实现了抽象表达式接口
class SubtractExpression(Expression):

    def __init__(self, expr_one, expr_two):
        Expression.__init__(self)
        self.expr_one = expr_one
        self.expr_two = expr_two

    # 覆盖表达式，执行context对象
    def interpret(self, context):
        print(
            self.__class__.__name__ + '::interpret() [context = ' +
            context.__class__.__name__ + ']', )
        return self.expr_one.interpret(context) - self.expr_two.interpret(context)