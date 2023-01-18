import { Flyweight } from './Flyweight.js'

// 具体享元角色，实现抽象接口，用于共享状态，一个类被创建以后就不用重复创建了
export class ConcreteFlyweight extends Flyweight {
  constructor(name) {
    super(name)
    // 内部状态，即不会随着环境的改变而改变的可共享部分
    // 这里的name也是对象保存的key
    this.name = name
    this.type = 'piano'
    console.log('ConcreteFlyweight::constructor(name) [创建具体享元' + name + ']')
  }

  // 这里state属于外部状态，由外部调用时传入
  // 也可以把非共享的对象传入进来
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
