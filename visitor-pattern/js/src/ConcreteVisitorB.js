import { Visitor } from './Visitor.js'

// 具体访问者B
export class ConcreteVisitorB extends Visitor {
  constructor() {
    super()
    // 假如由不同厂商是程序的访问者
    this.name = 'Apple Visitor'
  }

  visitA(concreteElement) {
    console.log(
      'ConcreteVisitorB::visitA() [Element.class = ' +
        concreteElement.constructor.name +
        ' Element.name = ' +
        concreteElement.getName() +
        ']'
    )
    concreteElement.operate()
  }

  visitB(concreteElement) {
    console.log(
      'ConcreteVisitorB::visitB() [Element.class = ' +
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
