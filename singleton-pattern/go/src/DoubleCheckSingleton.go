package src

import (
  "fmt"
  "sync"
)

// 安全懒汉模式的升级版，通过sync的Mutex实现双重检验
type DoubleCheckSingleton struct {
  name string
}

func (s *DoubleCheckSingleton) Run() {
  fmt.Println("DoubleCheckSingleton::run()", s.name)
}

// 定义私有变量，用来保存实例
var doubleCheckSingletonInstance *DoubleCheckSingleton
var lock = &sync.Mutex{}

// 是懒汉模式安升级版，双重检查来来支持延迟实例化单例对象
func GetDoubleCheckSingletonInstance(name string) *DoubleCheckSingleton {
  // 未实例化才进行加锁
  if doubleCheckSingletonInstance == nil {
    lock.Lock()
    defer lock.Unlock()
    // 为了保险，锁住之后再次检查是否已实例化
    if doubleCheckSingletonInstance == nil {
      doubleCheckSingletonInstance = &DoubleCheckSingleton{}
      doubleCheckSingletonInstance.name = name
    }
  }

  return doubleCheckSingletonInstance
}
