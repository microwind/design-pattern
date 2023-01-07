// 备忘录(Memento)角色，负责存储发起人传入的状态
export class Memento {
  constructor(state) {
    console.log(this.constructor.name + '::Memento() [state = ' + state + ']')
    this.state = state
  }

  getState() {
    return this.state
  }

  setState(state) {
    this.state = state
  }
}
