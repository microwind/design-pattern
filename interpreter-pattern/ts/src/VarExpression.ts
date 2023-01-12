import { Context } from './Context.js'
import { Expression } from './Expression.js'

// 命令模式真正的执行类，不直接对外，通过command来调用
// 构建变量表达式，或者叫终端表达式，其他表达式求值时通过层层追溯最后指向这里
// 变量与执行环境的Key对应，最终会通过key获取传入的值
export class VarExpression implements Expression {
  key: string
  constructor(key: string) {
    this.key = key
  }

  // 覆盖表达式，根据key获取变量
  interpret(context: Context) {
    const result = context.get(this.key)
    if (result === undefined) {
      console.error('error: this key is not found. [' + this.key + ']')
      return 0
    } else {
      return result
    }
  }
}
