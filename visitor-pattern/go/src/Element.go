package src

// (Element)抽象结构，提供定义Accept方法，传入抽象访问者
// go无抽象类，用interface替代
type Element interface {
  Accept(v Visitor)
  Operate()
  GetName() string
}
