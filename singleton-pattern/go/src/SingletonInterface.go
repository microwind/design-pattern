package src

import (
	"fmt"
	"sync"
)

// 懒汉模式单例，延迟实例化简单版
// 增加了一个接口
type SingletonInterface interface {
	Run()
}

// 定义类实现单例接口，用首字母小写来表示私有
type singleton struct {
	name string
}

// 实现Run方法
func (s singleton) Run() {
	fmt.Println("SingletonInterface::run()", s.name)
}

// 声明私有变量
var (
	instance *singleton
	syncOnce sync.Once
)

// 利用GetInstance返回SingletonInterface对象
func GetSingletonInterface(name string) SingletonInterface {
	// 利用sync.Once来实现一次实例化
	syncOnce.Do(func() {
		instance = &singleton{}
		instance.name = name
	})

	return instance
}
