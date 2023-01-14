package main

import (
  "fmt"

  "../src"
)

// main包下的main入口方法
func main() {
  fmt.Println("test start:")

  /**
   * 访问者模式是当客户需要访问具体各元素Element时，先建立一个访问者Visitor作为媒介
   * 客户基于对象结构ObjectStructure，调用Accept()，接受传入的访问者
   * 对象结构向其他元素负责分发访问者，元素对象接受之后会将自己回传给访问者，从而访问者可以访问具体元素
   */
  structure := src.ObjectStructure{}
  structure.Init()
  // 接受访问者A，把访问者传递给具体元素
  structure.Accept(&src.ConcreteVisitorA{})

  fmt.Println("====")
  // 接受访问者B，把访问者传递给具体元素
  structure.Accept(&src.ConcreteVisitorB{})
}

/**
jarry@jarrys-MacBook-Pro go % go build src/*.go
jarry@jarrys-MacBook-Pro go % go run test/test.go
test start:
ObjectStructure::Init()  Computer Structure
ObjectStructure::Accept() [Visitor.name = Google Visitor(struct=ConcreteVisitorA)]
ConcreteElementA::Accept() [Visitor.name = Google Visitor(struct=ConcreteVisitorA)]
ConcreteVisitorA::VisitA() [Element.name = Monitor Element(struct=ConcreteElementA)]
ConcreteElementA::Operate() [Monitor Element(struct=ConcreteElementA)]
ConcreteElementB::Accept() [Visitor.name = Google Visitor(struct=ConcreteVisitorA)]
ConcreteVisitorA::VisitB() [Element.name = Keyboard Element(struct=ConcreteElementB)]
ConcreteElementB::Operate() [Keyboard Element(struct=ConcreteElementB)]
====
ObjectStructure::Accept() [Visitor.name = Apple Visitor(struct=ConcreteVisitorB)]
ConcreteElementA::Accept() [Visitor.name = Apple Visitor(struct=ConcreteVisitorB)]
ConcreteVisitorB::VisitA() [Element.name = Monitor Element(struct=ConcreteElementA)]
ConcreteElementA::Operate() [Monitor Element(struct=ConcreteElementA)]
ConcreteElementB::Accept() [Visitor.name = Apple Visitor(struct=ConcreteVisitorB)]
ConcreteVisitorB::VisitB() [Element.name = Keyboard Element(struct=ConcreteElementB)]
ConcreteElementB::Operate() [Keyboard Element(struct=ConcreteElementB)]
*/
