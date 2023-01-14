package src

import (
  "fmt"
)

// 具体访问者A
type ConcreteVisitorA struct {
  name string
}

func (v *ConcreteVisitorA) GetName() string {
  v.name = "Google Visitor(struct=ConcreteVisitorA)"
  return v.name
}

func (v *ConcreteVisitorA) VisitA(e *ConcreteElementA) {
  fmt.Println(
    "ConcreteVisitorA::VisitA() [Element.name = " + e.GetName() + "]")
  e.Operate()
}

func (v *ConcreteVisitorA) VisitB(e *ConcreteElementB) {
  fmt.Println(
    "ConcreteVisitorA::VisitB() [Element.name = " + e.GetName() + "]")
  e.Operate()
}
