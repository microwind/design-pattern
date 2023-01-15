package src

import "fmt"

// 饿汉模式单例
type EagerSingleton struct {
  name string
}

func (s *EagerSingleton) Run() {
  fmt.Println("EagerSingleton::run()", s.name)
}

// 定义私有变量，用来保存实例
var eagerSingletonInstance *EagerSingleton

// 由主程序在初始化时执行，让实例保存在内存中，这样将获得唯一值
func EagerSingletonInit() {
  eagerSingletonInstance = new(EagerSingleton)
  // eagerSingletonInstance = &EagerSingleton{}
}

func GetEagerSingleton(name string) *EagerSingleton {
  // 如果name为空则赋值，已经赋值过了说明已经实例化了
  if eagerSingletonInstance.name == "" {
    eagerSingletonInstance.name = name
  }
  return eagerSingletonInstance
}
