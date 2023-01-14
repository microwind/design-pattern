package src

import (
  "fmt"
)

// 具体的元素实现者B
type ConcreteElementB struct {
  name string
}

func (c *ConcreteElementB) GetName() string {
  c.name = "Keyboard Element(struct=ConcreteElementB)"
  return c.name
}

func (e *ConcreteElementB) Accept(v Visitor) {
  fmt.Println(
    "ConcreteElementB::Accept() [Visitor.name = " + v.GetName() + "]")
  v.VisitB(e)
}

func (e *ConcreteElementB) Operate() {
  fmt.Println("ConcreteElementB::Operate() [" + e.GetName() + "]")
}
