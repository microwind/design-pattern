package src

import "fmt"

// 定义一个策略接口，注意go语言数据类型即接口
type Strategy interface {
	Run()
}

// 接口其他的方法，可选
func Init() {
	fmt.Print("strategy init!")
}
