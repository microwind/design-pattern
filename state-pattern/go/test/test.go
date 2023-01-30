package main

import (
	"fmt"

	"microwind/src"
)

// main包下的main入口方法
func main() {
  fmt.Println("test start:")

  /**
   * 状态模式就是对象Context在不同行为下有不同的状态，当前只有一种状态。
   * 通过行为的改变，状态也随之自动发生了改变。
   * 策略模式与状态模式类似，但策略模式是可以重新设置策略，而状态则通过行为来切换状态。
   */

  context := &src.Context{}
  // 初始状态是off
  context.SetState(&src.ConcreteStateOff{})
  // turn on
  context.TurnOn()
  // 再次turn on
  context.TurnOn()
  // turn off
  context.TurnOff()
  // 再次turn off
  context.TurnOff()
  fmt.Println("context.state: " + context.GetState().GetName())
}

/**
jarry@jarrys-MacBook-Pro go % go build src/*.go
jarry@jarrys-MacBook-Pro go % go run test/test.go
test start:
Context::SetState() [state = ConcreteStateOff]
ConcreteStateOff::On() [turn ON ok!]
Context::SetState() [state = ConcreteStateOn]
ConcreteStateOn::On() [needn't switch, state is ON.]
ConcreteStateOn::Off() [needn't switch, state is OFF.]
Context::SetState() [state = ConcreteStateOff]
ConcreteStateOff::Off() [needn't switch, state is OFF.]
context.state: ConcreteStateOff
*/
