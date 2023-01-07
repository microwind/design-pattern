import { Memento } from './Memento.js'

// 发起人(Originator)负责生成状态快照，即利用一个新备忘录对象将自己的内部状态存储起来
export class Originator {
  constructor() {
    this.state = undefined
  }

  // 每次创建一个新备忘录来保存状态
  saveMemento() {
    console.log(
      this.constructor.name + '::saveMemento() [state = ' + this.state + ']'
    )
    return new Memento(this.state)
  }

  // 从备忘录中恢复状态
  restoreMemento(memento) {
    this.state = memento.getState()
  }

  getState() {
    return this.state
  }

  setState(state) {
    this.state = state
  }
}
