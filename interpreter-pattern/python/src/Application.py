# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.Context import Context
from src.VarExpression import VarExpression
from src.AddExpression import AddExpression
from src.SubtractExpression import SubtractExpression
'''
* 解释器模式先构建执行上下文Context，然后构建一个最终的获取值的表达式VarExpression，这就构成了含上下文和变量-值的基本环境。
* 再将基本环境放到工具表达式里AddExpression或SubtractExpreesion进行计算，最终得到结果。
'''


class Application():

    # 构建两个数相加的例子
    @staticmethod
    def add_two(one, two):
        # 构建执行上下文环境
        context = Context()
        context.add('one', one)
        context.add('two', two)

        # 构建表达式
        var_one = VarExpression('one')
        var_two = VarExpression('two')

        # 再构建变量来进行计算，看起来啰嗦，但这样构建多种不同表达式计算就变得简单
        result = AddExpression(var_one, var_two)
        return result.interpret(context)

    # 构建连加计算的例子
    @staticmethod
    def add_more(*numbers):
        if (len(numbers) <= 1):
            return numbers[0]

        context = Context()
        # 构建执行环境
        for num in numbers:
            context.add('num' + str(num), num)

        # 先取出前两个作为计算基础
        var_one = VarExpression('num' + str(numbers[0]))
        var_two = VarExpression('num' + str(numbers[1]))
        # 再构建表达式，先赋值前两个
        expression = AddExpression(var_one, var_two)

        # 如果只有两个数则直接返回计算结果
        if len(numbers) == 2:
            return expression.interpret(context)

        # 如果数量超过两个则累加表达式再求值
        for i in range(2, len(numbers)):
            next_expression = VarExpression('num' + str(numbers[i]))
            # 表达式不断累加
            expression = AddExpression(expression, next_expression)

        return expression.interpret(context)

    # 计算前两个数相加，再减去后一个数的计算例子
    @staticmethod
    def add_and_subtract(one, two, three):
        # 构建执行上下文环境，有3个可操作的域
        context = Context()
        context.add('one', one)
        context.add('two', two)
        context.add('three', three)

        # 构建表达式，有3个变量
        var_one = VarExpression('one')
        var_two = VarExpression('two')
        var_three = VarExpression('three')

        # 再构建计算步骤，前两个用减法
        result = AddExpression(var_one, var_two)
        result = SubtractExpression(result, var_three)
        # 第3个用减法
        return result.interpret(context)
