import { State } from './State.js'
import { Context } from './Context.js'
import { ConcreteStateOn } from './ConcreteStateOn.js'

// 具体的状态实现者
export class ConcreteStateOff implements State {
  on(context: Context) {
    console.log(this.constructor.name + '::on() [turn ON ok!]')
    // 状态变为on后，状态类切换到ConcreteStateOn
    context.setState(new ConcreteStateOn())
  }

  off(context: Context) {
    // 当前是off状态，再点击off只是提示，不切换状态类
    console.log(
      this.constructor.name + '::off() [needn\'t switch, state is OFF.]'
    )
  }
}
