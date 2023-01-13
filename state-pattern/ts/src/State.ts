import { Context } from './Context.js'

// 定义状态接口和状态方法，当前context只有一种状态
export interface State {
  on(context: Context): void
  off(context: Context): void
}
