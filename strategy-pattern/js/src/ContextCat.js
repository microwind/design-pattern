import { Context } from './Context.js'
import { StrategyC } from './StrategyC.js'
export class ContextCat extends Context {
  constructor() {
    // 使用某个策略，这种模式类似bind，或者apply和call，JS在实现动态绑定上非常灵活
    super()
    console.log('ContextCat::setStrategy(StrategyC).')
    this.setStrategy(new StrategyC())
  }
}
