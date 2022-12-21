package src

import "fmt"

// 定义策略C
type StrategyC struct {
}

// 实现策略接口的对应方法
func (sc *StrategyC) Run() {
	fmt.Println("StrategyC::Run")
}
