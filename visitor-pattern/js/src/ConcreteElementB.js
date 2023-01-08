import { Element } from './Element.js'

// 具体的元素实现者B
export class ConcreteElementB extends Element {
  constructor() {
    super()
    this.name = 'Keyboard Element'
  }

  accept(visitor) {
    console.log(
      'ConcreteElementB::accept() [visitor.class = ' +
        visitor.constructor.name +
        ' visitor.name = ' +
        visitor.getName() +
        ']'
    )
    visitor.visit(this)
  }

  operate() {
    console.log('ConcreteElementB::operate() [' + this.getName() + ']')
  }

  getName() {
    return this.name
  }
}
