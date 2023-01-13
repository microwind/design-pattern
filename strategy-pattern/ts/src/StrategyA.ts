import { Strategy } from './Strategy.js'
export class StrategyA implements Strategy {
  run() {
    console.log('StrategyA::run().')
  }
}
