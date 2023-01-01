import { Flyweight } from './Flyweight.js'

// 无需共享的角色，每次都是新实例
export class UnsharedConcreteFlyweight extends Flyweight {
  constructor(name) {
    super(name)
    this.name = name
    this.type = 'guitar'
  }

  // 这里state属于外部状态，在调用时外部传入。
  operate(state) {
    console.log(
      `${this.constructor.name}::operate() [${this.getName()}, ${this.getType()}, ${state}])`
    )
  }

  getName() {
    return this.name
  }

  getType() {
    return this.type
  }
}
