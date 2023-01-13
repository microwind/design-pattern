import { Strategy } from './Strategy.js'
export class StrategyB implements Strategy {
  run() {
    console.log('StrategyB::run().')
  }
}
