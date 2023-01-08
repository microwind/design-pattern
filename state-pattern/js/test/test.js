import { Context } from '../src/Context.js'
import { ConcreteStateOff } from '../src/ConcreteStateOff.js'

export function test() {
  /**
   * 状态模式就是不同的状态下有不同的行为，当前对象只有一种状态
   * 策略模式可以重新设置策略，状态则通过动作来切换
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
