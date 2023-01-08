import { Visitor } from './Visitor.js'

// 具体访问者B
export class ConcreteVisitorB extends Visitor {
  constructor() {
    super()
    // 假如由不同厂商是程序的访问者
    this.name = 'Apple Visitor'
  }

  visit(concreteElement) {
    console.log(
      'ConcreteVisitorB::visit() [Element.class = ' +
        concreteElement.constructor.name +
        ' Element.name = ' +
        concreteElement.getName() +
        ']'
    )
    concreteElement.operate()
  }

  getName() {
    return this.name
  }
}
