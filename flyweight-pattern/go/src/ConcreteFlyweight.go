package src

import "fmt"

// 具体享元角色，实现抽象接口，用于共享状态，一个类被创建以后就不用重复创建了
type ConcreteFlyweight struct {
  // 内部状态，即不会随着环境的改变而改变的可共享部分
  // 这里的name也是对象保存的key
  name string
  kind string
}

// 这里state属于外部状态，由外部调用时传入
// 也可以把非共享的对象传入进来
func (c *ConcreteFlyweight) Operate(state string) {
  fmt.Println("ConcreteFlyweight::Operate() [", c.GetName(), c.kind, state, "]")
}

func (c *ConcreteFlyweight) GetName() string {
  return c.name
}
