import { State } from './State.js'
import { ConcreteStateOff } from './ConcreteStateOff.js'

// 具体的状态实现者
export class ConcreteStateOn extends State {
  on(context) {
    // 当前是on状态，再点击on只是提示，不切换状态类
    console.log(this.constructor.name + "::on() [needn't switch, state is ON.]")
  }

  off(context) {
    // 状态变为off后，状态类切换到ConcreteStateOff
    console.log(
      this.constructor.name + "::off() [needn't switch, state is OFF.]"
    )
    context.setState(new ConcreteStateOff())
  }
}
