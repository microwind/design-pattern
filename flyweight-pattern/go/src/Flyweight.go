package src

// 享元角色抽象接口
type Flyweight interface {
  GetName() string
  Operate(state string)
}
