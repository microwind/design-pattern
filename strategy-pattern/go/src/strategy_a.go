package src

import "fmt"

// 定义策略A
type StrategyA struct {
}

// 实现策略接口的对应方法
func (s *StrategyA) Run() {
	fmt.Println("StrategyA::Run")
}
