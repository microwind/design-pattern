package src

import "fmt"

// 无需共享实例的角色，用于处理外部非共享状态
// 当不需要共享时用这样的类
type UnsharedConcreteFlyweight struct {
  name string
  kind string
}

// 非共享对象的外部状态
func (u *UnsharedConcreteFlyweight) Operate(state string) {
  fmt.Println("UnsharedConcreteFlyweight::Operate() [", u.GetName(), u.kind, state, "]")
}

func (u *UnsharedConcreteFlyweight) GetName() string {
  return u.name
}
