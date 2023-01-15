package src

import "fmt"

// 具体的状态实现者
type ConcreteStateOn struct {
  state State
}

func (c *ConcreteStateOn) GetName() string {
  return "ConcreteStateOn"
}

func (c *ConcreteStateOn) On(context *Context) {
  // 当前是on状态，再点击on只是提示，不切换状态类
  fmt.Println("ConcreteStateOn::On() [needn't switch, state is ON.]")
}

func (c *ConcreteStateOn) Off(context *Context) {
  // 状态变为off后，状态类切换到ConcreteStateOff
  fmt.Println("ConcreteStateOn::Off() [needn't switch, state is OFF.]")
  context.SetState(&ConcreteStateOff{})
}
