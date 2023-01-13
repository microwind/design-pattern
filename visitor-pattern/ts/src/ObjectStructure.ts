import { Element } from './Element.js'
import { Visitor } from './Visitor.js'
import { ConcreteElementA } from './ConcreteElementA.js'
import { ConcreteElementB } from './ConcreteElementB.js'

// 结构对象(ObjectStructure)
export class ObjectStructure {
  name: string
  elements: Element[]
  constructor() {
    // 可以想象为一台电脑，聚合了各种设备元素
    this.name = 'Computer Structure'
    this.elements = new Array<Element>()
    // 结构对象初始化聚合了其他元素
    this.addElement(new ConcreteElementA())
    this.addElement(new ConcreteElementB())
  }

  addElement(element: Element) {
    this.elements.push(element)
  }

  // 传入访问者分发给其他元素
  accept(visitor: Visitor) {
    console.log(
      'ObjectStructure::accept() [visitor.class = ' +
        visitor.constructor.name +
        ' visitor.name = ' +
        visitor.getName() +
        ']'
    )
    for (const element of this.elements) {
      element.accept(visitor)
    }
  }

  getName() {
    return this.name
  }
}
