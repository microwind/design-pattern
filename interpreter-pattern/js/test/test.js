import { Application } from '../src/Application.js'

export function test() {
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
// npm run
jarry@jarrys-MacBook-Pro js % npm run test
// or node execution
jarry@jarrys-MacBook-Pro js % node test/test.js
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
*/
