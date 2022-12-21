package src

import "fmt"

// 定义具体执行对象，调用依赖Context
type ContextDog struct {
	context Context
}

// 可提前绑定具体的策略
func (c *ContextDog) Init() {
	c.context.SetStrategy(&StrategyB{})
	fmt.Println("ContextDog::init. setStrategy(StrategyB)")
}

// 调用策略方法
func (c *ContextDog) Run() {
	fmt.Println("ContextDog::run")
	c.context.Run()
}
