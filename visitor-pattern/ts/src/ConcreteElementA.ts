import { Element } from './Element.js'
import { Visitor } from './Visitor.js'

// 具体的元素实现者A
export class ConcreteElementA extends Element {
  constructor() {
    super()
    // 可以设想为显示器
    this.name = 'Monitor Element'
  }

  override accept(visitor: Visitor) {
    console.log(
      'ConcreteElementA::accept() [visitor.class = ' +
        visitor.constructor.name +
        ' visitor.name = ' +
        visitor.getName() +
        ']'
    )
    visitor.visit(this)
  }

  override operate() {
    console.log('ConcreteElementA::operate() [' + this.getName() + ']')
  }
}
