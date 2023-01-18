import { Flyweight } from './Flyweight.js'

// 无需共享实例的角色，用于处理外部非共享状态
// 当不需要共享时用这样的类
export class UnsharedConcreteFlyweight extends Flyweight {
  constructor(name) {
    super(name)
    this.name = name
    this.type = 'guitar'
    console.log('UnsharedConcreteFlyweight::constructor(name) [创建非共享对象' + name + ']')
  }

  // 非共享对象的外部状态
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
