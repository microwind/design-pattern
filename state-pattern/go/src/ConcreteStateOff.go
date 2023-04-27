package src

import "fmt"

// 具体的状态实现者
type ConcreteStateOff struct {
  Name string
}

func (c *ConcreteStateOff) GetName() string {
  if c.Name == "" {
    c.Name = "ConcreteStateOff"
  }
  return c.Name
}

func (c *ConcreteStateOff) On(context *Context) {
  fmt.Println("ConcreteStateOff::On() [turn ON ok!]")
  // 状态变为on后，状态类切换到ConcreteStateOn
  context.SetState(&ConcreteStateOn{})
}

func (c *ConcreteStateOff) Off(context *Context) {
  // 当前是off状态，再点击off只是提示，不切换状态类
  fmt.Println("ConcreteStateOff::Off() [needn't switch, state is OFF.]")
}
