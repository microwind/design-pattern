export class Context {
  strategy = null

  constructor() {
    // console.log('Context::init()')
  }

  setStrategy(strategy) {
    this.strategy = strategy
  }

  action() {
    this.strategy.run()
  }

}
