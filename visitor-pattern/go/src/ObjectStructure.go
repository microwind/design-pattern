package src

import (
  "fmt"
)

// 结构对象(ObjectStructure)
type ObjectStructure struct {
  name     string
  elements []Element
}

func (o *ObjectStructure) AddElement(e Element) {
  o.elements = append(o.elements, e)
}

// 传入访问者分发给其他元素
func (o *ObjectStructure) Accept(v Visitor) {
  fmt.Println(
    "ObjectStructure::Accept() [Visitor.name = " +
      v.GetName() + "]")

  // 通知全部元素成员接受访问者
  for i := 0; i < len(o.elements); i++ {
    o.elements[i].Accept(v)
  }

  // for _, ele := range o.elements {
  //   ele.Accept(v)
  // }
}

func (o *ObjectStructure) GetName() string {
  o.name = "Computer Structure"
  return o.name
}

// 全局的函数，从这里开始
func (o *ObjectStructure) Init() {
  // 可以想象为一台电脑，聚合了各种设备元素
  fmt.Println("ObjectStructure::Init() ", o.GetName())
  // 定义一个对象数组，长度可选
  o.elements = make([]Element, 0, 100)

  // 结构对象初始化聚合了其他元素
  o.AddElement(&ConcreteElementA{})
  o.AddElement(&ConcreteElementB{})
}
