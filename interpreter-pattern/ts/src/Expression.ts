import { Context } from './Context.js'

// 抽象表达式接口，根据业务场景规范表达式
export interface Expression {
  interpret(context: Context): number
}
