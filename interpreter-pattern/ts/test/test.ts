import { Application } from '../src/Application.js'

export function test() {
  /**
   * 解释器模式实现了一个表达式接口，该接口可以解释一个特定的上下文的变量和语句。
   * 也就是先定义上下文，然后定义变量，再使用表达式进行求值。相当可以构造一个简单的语法解析器。
   */
  const result1 = Application.addTwo(1, 2)
  console.log('result1: ' + result1)

  const result2 = Application.addMore(1, 2, 3, 4, 5)
  console.log('result2: ' + result2)

  const result3 = Application.addAndSubtract(3, 4, 5)
  console.log('result3: ' + result3)
}

// 执行测试
;(function () {
  console.log('test start:')
  test()
})()
/**
jarry@jarrys-MacBook-Pro ts % tsc
jarry@jarrys-MacBook-Pro ts % node test/test.js
test start:
AddExpression::interpret() [context = Context]
result1: 3
AddExpression::interpret() [context = Context]
AddExpression::interpret() [context = Context]
AddExpression::interpret() [context = Context]
AddExpression::interpret() [context = Context]
result2: 15
SubtractExpression::interpret() [context = Context]
AddExpression::interpret() [context = Context]
result3: 2
jarry@jarrys-MacBook-Pro ts % ts-node-esm test/test.ts
*/
