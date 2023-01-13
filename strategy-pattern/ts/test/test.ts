import { ContextCat } from '../src/ContextCat.js'
import { ContextDog } from '../src/ContextDog.js'
import { StrategyA } from '../src/StrategyA.js'

export function test() {
  /**
   * 策略模式就是根据需要给对象绑定具体策略，使得具体实现和策略可以灵活搭配。
   * 先声明某个具体Context对象，该对象已经绑定了具体策略，同时还可以更改策略。
   * 注意，TS本身有bind函数，可以用动态给函数绑定调用者，达到策略模式效果，而无需这种方式来实现。
   */

  // 实例化某个内容，策略已经绑定上
  const contextCat = new ContextCat()
  contextCat.action()

  // 重新设置策略
  console.log("reset contextCat'strategy to StrategyA.")
  contextCat.setStrategy(new StrategyA())
  contextCat.action()

  // 实例化某个内容，策略已经绑定上
  const contextGog = new ContextDog()
  contextGog.action()
}

// 执行测试
;(function () {
  console.log('test start:')
  test()
})()
/**
// use ems
jarry@jarrys-MacBook-Pro ts % ts-node-esm test/test.ts
// or tsc and node run
jarry@jarrys-MacBook-Pro ts % tsc
jarry@jarrys-MacBook-Pro ts % node test/test.js
test start:
ContextCat::setStrategy(StrategyC).
StrategyC::run().
reset contextCat'strategy to StrategyA.
StrategyA::run().
ContextDog::setStrategy(StrategyB).
StrategyB::run().
*/
