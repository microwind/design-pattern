import { Context } from './Context.js'
import { StrategyB } from './StrategyB.js'
export class ContextDog extends Context {
  constructor() {
    // 使用某个策略
    super()
    console.log('ContextDog::setStrategy(StrategyB).')
    this.setStrategy(new StrategyB())
  }
}
