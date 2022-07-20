import { Context } from './Context.js'
import { StrategyC } from './StrategyC.js'
export class ContextCat extends Context {
  constructor() {
    // 使用某个策略
    super()
    console.log('ContextCat::setStrategy(StrategyC).')
    this.setStrategy(new StrategyC())
  }
}
