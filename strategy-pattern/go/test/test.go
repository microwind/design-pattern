package main

import (
	"fmt"

	"../src"
)

// main包下的main入口方法
func main() {
	fmt.Println("test start:")
	// 这里src.Init来自strategy.go文件
	src.Init()

	/**
	 * 策略模式就是根据需要给对象绑定具体策略，使得具体实现和策略可以灵活搭配。
	 * 先声明某个具体Context对象，该对象已经绑定了具体策略，同时还可以更改策略。
	 */

	// 声明策略执行对象
	context := src.Context{}

	// 设置策略A
	context.SetStrategy(&src.StrategyA{})

	// 执行策略A，打印StrategyA
	context.Run()

	// 设置策略B
	context.SetStrategy(&src.StrategyB{})
	// 执行策略B，打印StrategyB
	context.Run()

	// 执行策略C，打印StrategyC
	context.SetStrategy(&src.StrategyC{})
	context.Run()

	// /*********************** 分割线 ******************************************/

	// 直接实例化具体执行对象，策略已经绑定
	contextCat := src.ContextCat{}
	contextCat.Init()
	contextCat.Run()

	// 直接实例化具体执行对象，策略已经绑定
	contextDog := src.ContextDog{}
	contextDog.Init()
	contextDog.Run()
}

/**
jarry@jarrys-MacBook-Pro go % pwd
/Users/jarry/github/design-pattern/strategy-pattern/go
jarry@jarrys-MacBook-Pro go % go version
go version go1.15 darwin/amd64
jarry@jarrys-MacBook-Pro go % go build src/*.go
jarry@jarrys-MacBook-Pro go % go run test/test.go
test start:
strategy init!
StrategyA::Run
StrategyB::Run
StrategyC::Run
ContextCat::init. setStrategy(StrategyC)
ContextCat::run
StrategyC::Run
ContextDog::init. setStrategy(StrategyB)
ContextDog::run
StrategyB::Run
*/
