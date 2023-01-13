import { Strategy } from './Strategy.js'

export abstract class Context {
  strategy: Strategy

  constructor() {
    // console.log('Context::init()')
  }

  setStrategy(strategy: Strategy) {
    this.strategy = strategy
  }

  action() {
    this.strategy.run()
  }
}
