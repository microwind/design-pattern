package src

import (
  "fmt"
)

// 具体的元素实现者A
type ConcreteElementA struct {
  name string
}

func (c *ConcreteElementA) GetName() string {
  c.name = `Monitor Element(struct=ConcreteElementA)`
  return c.name
}

func (e *ConcreteElementA) Accept(v Visitor) {
  fmt.Println(
    "ConcreteElementA::Accept() [Visitor.name = " + v.GetName() + "]")
  v.VisitA(e)
}

func (e *ConcreteElementA) Operate() {
  fmt.Println("ConcreteElementA::Operate() [" + e.GetName() + "]")
}
