import { Visitor } from './Visitor.js'
import { ConcreteElementA } from './ConcreteElementA.js'
import { ConcreteElementB } from './ConcreteElementB.js'

// 具体访问者A
export class ConcreteVisitorA implements Visitor {
  name: string
  constructor() {
    // 假如由不同厂商是程序的访问者
    this.name = 'Google Visitor'
  }

  // TS实现函数重载
  visit(concreteElement: ConcreteElementA): void
  visit(concreteElement: ConcreteElementB): void
  visit(concreteElement: ConcreteElementA | ConcreteElementB) {
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
