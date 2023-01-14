package src

import (
  "fmt"
)

// 具体访问者B
type ConcreteVisitorB struct {
  name string
}

func (v *ConcreteVisitorB) GetName() string {
  v.name = "Apple Visitor(struct=ConcreteVisitorB)"
  return v.name
}

func (v *ConcreteVisitorB) VisitB(e *ConcreteElementB) {
  fmt.Println(
    "ConcreteVisitorB::VisitB() [Element.name = " + e.GetName() + "]")
  e.Operate()
}

func (v *ConcreteVisitorB) VisitA(e *ConcreteElementA) {
  fmt.Println(
    "ConcreteVisitorB::VisitA() [Element.name = " + e.GetName() + "]")
  e.Operate()
}
