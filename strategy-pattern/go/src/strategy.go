package src

import "fmt"

// 定义一个策略接口，注意go语言数据类型即接口
type Strategy interface {
	Run()
}

// 写在接口文件的其他全局方法
func Init() {
	fmt.Println("strategy init!")
}
