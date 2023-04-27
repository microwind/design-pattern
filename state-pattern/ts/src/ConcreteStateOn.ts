import { State } from './State.js'
import { Context } from './Context.js'
import { ConcreteStateOff } from './ConcreteStateOff.js'

// 具体的状态实现者
export class ConcreteStateOn implements State {
  on(context: Context) {
    // 当前是on状态，再点击on只是提示，不切换状态类
    console.log(this.constructor.name + "::on() [needn't switch, state is ON.]")
  }

  off(context: Context) {
    // 状态变为off后，状态类切换到ConcreteStateOff
    console.log(
      this.constructor.name + '::off() [turn OFF ok!]'
    )
    context.setState(new ConcreteStateOff())
  }
}
