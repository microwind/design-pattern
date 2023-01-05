import { Expression } from './Expression.js'

// 具体表达式，实现了抽象表达式接口
export class AddExpression extends Expression {
  constructor(exprOne, exprTwo) {
    super()
    this.exprOne = exprOne
    this.exprTwo = exprTwo
  }

  // 覆盖表达式，执行context对象
  interpret(context) {
    console.log(
      this.constructor.name +
        '::interpret() [context = ' +
        context.constructor.name +
        ']',
    )
    return this.exprOne.interpret(context) + this.exprTwo.interpret(context)
  }
}
