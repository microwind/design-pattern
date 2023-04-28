import { Element } from './Element.js'

// 具体的元素实现者A
export class ConcreteElementA extends Element {
  constructor() {
    super()
    // 可以设想为显示器
    this.name = 'Monitor Element'
  }

  accept(visitor) {
    console.log(
      'ConcreteElementA::accept() [visitor.class = ' +
        visitor.constructor.name +
        ' visitor.name = ' +
        visitor.getName() +
        ']'
    )
    visitor.visitA(this)
  }

  operate() {
    console.log('ConcreteElementA::operate() [' + this.getName() + ']')
  }

  getName() {
    return this.name
  }
}
