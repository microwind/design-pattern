import { State } from './State.js'

// 具体执行实体类，内部关联状态
export class Context {
  state: State
  constructoror(state: State) {
    this.state = state
  }

  getState() {
    return this.state
  }

  setState(state: State) {
    console.log(
      this.constructor.name +
        '::setState() [state = ' +
        state.constructor.name +
        ']'
    )
    this.state = state
  }

  turnOn() {
    this.state.on(this)
  }

  turnOff() {
    this.state.off(this)
  }
}
