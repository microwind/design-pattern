package src

import "fmt"

// 定义具体执行对象，Go没有继承，用聚合来调用Context里的函数
type ContextCat struct {
	context Context
}

// 可提前绑定具体的策略
func (c *ContextCat) Init() {
	c.context.SetStrategy(&StrategyC{})
	fmt.Println("ContextCat::init. setStrategy(StrategyC)")
}

// 调用策略方法
func (c *ContextCat) Run() {
	fmt.Println("ContextCat::run")
	c.context.Run()
}
