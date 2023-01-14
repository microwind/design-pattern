package src

// 访问者Visitor抽象接口，定义Visit方法，传递具体元素对象
// 注意这里与Java、JS、Python的区别
// go不支持重载，不允许名称相同，但区分不同类型形参，需要为不同Visitor定义不同的Visit函数
type Visitor interface {
  VisitA(e *ConcreteElementA)
  VisitB(e *ConcreteElementB)
  GetName() string
}
