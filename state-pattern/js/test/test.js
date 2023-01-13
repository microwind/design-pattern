import { Context } from '../src/Context.js'
import { ConcreteStateOff } from '../src/ConcreteStateOff.js'

export function test() {
  /**
   * 状态模式就是对象Context在不同行为下有不同的状态，当前只有一种状态。
   * 通过行为的改变，状态也随之自动发生了改变。
   * 策略模式与状态模式类似，但策略模式是可以重新设置策略，而状态则通过行为来切换状态。
   */

  const context = new Context()
  // 初始状态是off
  context.setState(new ConcreteStateOff())
  // turn on
  context.turnOn()
  // 再次turn on
  context.turnOn()
  // turn off
  context.turnOff()
  // 再次turn off
  context.turnOff()
  console.log('context.state: ' + context.getState().constructor.name)
}

// 执行测试
;(function () {
  console.log('test start:')
  test()
})()
/**
// npm run
jarry@jarrys-MacBook-Pro js % npm run test
// or node execution
jarry@jarrys-MacBook-Pro js % node test/test.js
test start:
Context::setState() [state = ConcreteStateOff]
ConcreteStateOff::on() [turn ON ok!]
Context::setState() [state = ConcreteStateOn]
ConcreteStateOn::on() [needn't switch, state is ON.]
ConcreteStateOn::off() [needn't switch, state is OFF.]
Context::setState() [state = ConcreteStateOff]
ConcreteStateOff::off() [needn't switch, state is OFF.]
context.state: ConcreteStateOff
*/
