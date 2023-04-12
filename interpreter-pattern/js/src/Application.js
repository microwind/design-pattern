import { Context } from './Context.js'
import { VarExpression } from './VarExpression.js'
import { AddExpression } from './AddExpression.js'
import { SubtractExpression } from './SubtractExpression.js'
export class Application {
  /*
   * 解释器模式先构建执行上下文Context，然后构建一个最终的获取值的表达式VarExpression，这就构成了含上下文和变量-值的基本环境。
   * 再将基本环境放到工具表达式里AddExpression或SubtractExpreesion进行计算，最终得到结果。
   */

  // 构建两个数相加的例子
  static addTwo(one, two) {
    // 构建执行上下文环境
    const context = new Context()
    context.add('one', one)
    context.add('two', two)

    // 构建表达式
    const varOne = new VarExpression('one')
    const varTwo = new VarExpression('two')

    // 再构建变量来进行计算，看起来啰嗦，但这样构建多种不同表达式计算就变得简单
    const result = new AddExpression(varOne, varTwo)
    return result.interpret(context)
  }

  // 构建连加计算的例子
  static addMore(...numbers) {
    if (numbers.length <= 1) {
      return numbers[0]
    }

    const context = new Context()
    // 构建执行环境
    for (const num of numbers) {
      context.add('num' + num, num)
    }

    // 先取出前两个作为计算基础
    const varOne = new VarExpression('num' + numbers[0])
    const varTwo = new VarExpression('num' + numbers[1])
    // 再构建表达式，先赋值前两个
    let expression = new AddExpression(varOne, varTwo)

    // 如果只有两个数则直接返回计算结果
    if (numbers.length === 2) {
      return expression.interpret(context)
    }

    // 如果数量超过两个则累加表达式再求值
    for (let i = 2; i < numbers.length; i++) {
      const nextExpression = new VarExpression('num' + numbers[i])
      // 表达式不断累加
      expression = new AddExpression(expression, nextExpression)
    }

    return expression.interpret(context)
  }

  // 计算前两个数相加，再减去后一个数的计算例子
  static addAndSubtract(one, two, three) {
    // 构建执行上下文环境，有3个可操作的域
    const context = new Context()
    context.add('one', one)
    context.add('two', two)
    context.add('three', three)

    // 构建表达式，有3个变量
    const varOne = new VarExpression('one')
    const varTwo = new VarExpression('two')
    const varThree = new VarExpression('three')

    // 再构建计算步骤，前两个用加法
    let result = new AddExpression(varOne, varTwo)
    result = new SubtractExpression(result, varThree)
    // 第3个用减法
    return result.interpret(context)
  }
}
