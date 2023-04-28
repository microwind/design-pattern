import { ObjectStructure } from '../src/ObjectStructure.js'
import { ConcreteVisitorA } from '../src/ConcreteVisitorA.js'
import { ConcreteVisitorB } from '../src/ConcreteVisitorB.js'

function test() {
  /**
   * 访问者模式是当客户需要访问具体各元素Element时，先建立一个访问者Visitor作为媒介
   * 客户基于对象结构ObjectStructure，调用accept()，接受传入的访问者
   * 对象结构向其他元素负责分发访问者，元素对象接受之后会将自己回传给访问者，从而访问者可以访问具体元素
   */
  const structure = new ObjectStructure()
  // 接受访问者A，把访问者传递给具体元素
  structure.accept(new ConcreteVisitorA())

  console.log('====')
  // 接受访问者B，把访问者传递给具体元素
  structure.accept(new ConcreteVisitorB())
}

// 执行测试
;(function () {
  console.log('test start:')
  test()
})()
/**
// npm run
jarry@jarrys-MacBook-Pro js % npm run test
// or node execution
jarry@jarrys-MacBook-Pro js % node test/test.js
test start:
ObjectStructure::accept() [visitor.class = ConcreteVisitorA visitor.name = Google Visitor]
ConcreteElementA::accept() [visitor.class = ConcreteVisitorA visitor.name = Google Visitor]
ConcreteVisitorA::visitA() [Element.class = ConcreteElementA Element.name = Monitor Element]
ConcreteElementA::operate() [Monitor Element]
ConcreteElementB::accept() [visitor.class = ConcreteVisitorA visitor.name = Google Visitor]
ConcreteVisitorA::visitB() [Element.class = ConcreteElementB Element.name = Keyboard Element]
ConcreteElementB::operate() [Keyboard Element]
====
ObjectStructure::accept() [visitor.class = ConcreteVisitorB visitor.name = Apple Visitor]
ConcreteElementA::accept() [visitor.class = ConcreteVisitorB visitor.name = Apple Visitor]
ConcreteVisitorB::visitA() [Element.class = ConcreteElementA Element.name = Monitor Element]
ConcreteElementA::operate() [Monitor Element]
ConcreteElementB::accept() [visitor.class = ConcreteVisitorB visitor.name = Apple Visitor]
ConcreteVisitorB::visitB() [Element.class = ConcreteElementB Element.name = Keyboard Element]
ConcreteElementB::operate() [Keyboard Element]
*/
