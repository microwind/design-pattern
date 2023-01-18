package src

import "strconv"

/*
 * 解释器模式先构建执行上下文Context，然后构建一个最终的获取值的表达式VarExpression，这就构成了含上下文和变量-值的基本环境。
 * 再将基本环境放到工具表达式里AddExpression或SubtractExpreesion进行计算，最终得到结果。
 */
type Application struct {
}

// 构建两个数相加的例子
func (a *Application) AddTwo(one int, two int) int {
  // 构建执行上下文环境
  var context = new(Context)
  context.Add("one", one)
  context.Add("two", two)

  // 构建表达式
  var varOne = &VarExpression{key: "one"}
  var varTwo = &VarExpression{key: "two"}

  // 再构建变量来进行计算，看起来啰嗦，但这样构建多种不同表达式计算就变得简单
  var result = &AddExpression{
    exprOne: varOne,
    exprTwo: varTwo,
  }
  return result.Interpret(*context)
}

// 构建连加计算的例子
func (a *Application) AddMore(numbers ...int) int {
  if len(numbers) <= 1 {
    return numbers[0]
  }

  var context = new(Context)
  // 构建执行环境
  for _, num := range numbers {
    context.Add(""+strconv.Itoa(num), num)
  }

  // 先取出前两个作为计算基础
  var varOne = &VarExpression{key: "" + strconv.Itoa(numbers[0])}
  var varTwo = &VarExpression{key: "" + strconv.Itoa(numbers[1])}
  // 再构建表达式，先赋值前两个
  var expression = &AddExpression{
    exprOne: varOne,
    exprTwo: varTwo,
  }

  // 如果只有两个数则直接返回计算结果
  if len(numbers) == 2 {
    return expression.Interpret(*context)
  }

  // 如果数量超过两个则累加表达式再求值
  for i := 2; i < len(numbers); i++ {
    var nextExpression = &VarExpression{
      key: "" + strconv.Itoa(numbers[i]),
    }
    // 表达式不断累加
    expression = &AddExpression{
      exprOne: expression,
      exprTwo: nextExpression,
    }
  }

  return expression.Interpret(*context)
}

// 计算前两个数相加，再减去后一个数的计算例子
func (a *Application) AddAndSubtract(one int, two int, three int) int {
  // 构建执行上下文环境，有3个可操作的域
  var context = &Context{}
  context.Add("one", one)
  context.Add("two", two)
  context.Add("three", three)

  // 构建表达式，有3个变量
  var varOne = &VarExpression{key: "one"}
  var varTwo = &VarExpression{key: "two"}
  var varThree = &VarExpression{key: "three"}

  // 再构建计算步骤，前两个用减法
  var result Expression

  result = &AddExpression{
    exprOne: varOne,
    exprTwo: varTwo,
  }
  result = &SubtractExpression{
    exprOne: result,
    exprTwo: varThree,
  }
  // 第3个用减法
  return result.Interpret(*context)
}
