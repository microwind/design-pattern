package src

import "fmt"

// 具体的状态实现者
// 策略模式与状态模式都是将策略/状态绑定到执行对象(Context)上
// 不同的是策略模式是客户可设定策略，而状态则是通过状态动作来实现改变
type ConcreteStateOn struct {
  Name string
}

func (c *ConcreteStateOn) GetName() string {
  if c.Name == "" {
    c.Name = "ConcreteStateOn"
  }
  return c.Name
}

func (c *ConcreteStateOn) On(context *Context) {
  // 当前是on状态，再点击on只是提示，不切换状态类
  fmt.Println("ConcreteStateOn::On() [needn't switch, state is ON.]")
}

func (c *ConcreteStateOn) Off(context *Context) {
  // 状态变为off后，状态类切换到ConcreteStateOff
  fmt.Println("ConcreteStateOn::Off() [turn OFF ok!]")
  // 此处状态对象可以每次是新实例，也可以外部传入
  context.SetState(&ConcreteStateOff{})
}
