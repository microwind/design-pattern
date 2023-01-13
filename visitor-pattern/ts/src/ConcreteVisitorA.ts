import { Visitor } from './Visitor.js'
import { Element } from './Element.js'

// 具体访问者A
export class ConcreteVisitorA implements Visitor {
  name: string;
  constructor() {
    // 假如由不同厂商是程序的访问者
    this.name = 'Google Visitor'
  }

  visit(concreteElement: Element) {
    console.log(
      'ConcreteVisitorA::visit() [Element.class = ' +
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
