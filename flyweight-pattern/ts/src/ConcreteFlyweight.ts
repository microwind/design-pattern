import { Flyweight } from './Flyweight.js'

// 具体享元角色，实现抽象接口，用于执行实际操作
export class ConcreteFlyweight implements Flyweight {
  name: string
  type: string
  constructor(name: string) {
    // 内部状态，即不会随着环境的改变而改变的可共享部分
    // 这里的name也是对象保存的key
    this.name = name
    this.type = 'piano'
    console.log('ConcreteFlyweight::constructor(name) [创建具体享元' + name + ']')
  }

  // 这里state属于外部状态，由外部调用时传入
  // 也可以把非共享的对象传入进来
  operate(state: string) {
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
