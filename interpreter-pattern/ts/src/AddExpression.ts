import { Context } from './Context.js'
import { Expression } from './Expression.js'

// 具体表达式，实现了抽象表达式接口
export class AddExpression implements Expression {
  exprOne: Expression
  exprTwo: Expression
  constructor(exprOne: Expression, exprTwo: Expression) {
    this.exprOne = exprOne
    this.exprTwo = exprTwo
  }

  // 覆盖表达式，执行context对象
  interpret(context: Context) {
    console.log(
      this.constructor.name +
        '::interpret() [context = ' +
        context.constructor.name +
        ']'
    )
    return this.exprOne.interpret(context) + this.exprTwo.interpret(context)
  }
}
