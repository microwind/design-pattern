package src

import "fmt"

// 具体执行实体类，内部关联状态
type Context struct {
  state State
}

func (c *Context) GetState() State {
  return c.state
}

func (c *Context) SetState(state State) {
  fmt.Println("Context::SetState() [state = " + state.GetName() + "]")
  c.state = state
}

func (c *Context) TurnOn() {
  c.state.On(c)
}

func (c *Context) TurnOff() {
  c.state.Off(c)
}
