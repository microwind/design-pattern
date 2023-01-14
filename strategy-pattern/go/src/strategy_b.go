package src

import "fmt"

// 定义策略B
type StrategyB struct {
}

// 实现策略接口的对应方法
func (s *StrategyB) Run() {
	fmt.Println("StrategyB::Run")
}
