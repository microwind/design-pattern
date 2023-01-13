import { Element } from './Element.js'
import { Visitor } from './Visitor.js'

// 具体的元素实现者B
export class ConcreteElementB extends Element {
  constructor() {
    super()
    this.name = 'Keyboard Element'
  }

  override accept(visitor: Visitor) {
    console.log(
      'ConcreteElementB::accept() [visitor.class = ' +
        visitor.constructor.name +
        ' visitor.name = ' +
        visitor.getName() +
        ']'
    )
    visitor.visit(this)
  }

  override operate() {
    console.log('ConcreteElementB::operate() [' + this.getName() + ']')
  }
}
