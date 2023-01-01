import { Context } from './Context.js'
import { StrategyB } from './StrategyB.js'
export class ContextDog extends Context {
  constructor() {
    // 使用某个策略，这种模式类似bind，或者apply和call，JS在实现动态绑定上非常灵活
    super()
    console.log('ContextDog::setStrategy(StrategyB).')
    this.setStrategy(new StrategyB())
  }
}
