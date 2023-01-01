import { Flyweight } from './Flyweight.js'

// 具体享元角色，实现抽象接口，用于执行实际操作
export class ConcreteFlyweight extends Flyweight {
  constructor(name) {
    super(name)
    this.name = name
    this.type = 'piano'
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
