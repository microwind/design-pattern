package src

import (
  "fmt"
  "sync"
)

// 懒汉模式单例，延迟实例化，导入sync包，利用once来提升安全
type LazySingletonSafe struct {
  name string
}

func (s *LazySingletonSafe) Run() {
  fmt.Println("LazySingletonSafe::run()", s.name)
}

// 定义私有变量
var lazySingletonSafeInstance *LazySingletonSafe
var once = &sync.Once{}

// 外部函数，用来实例化类
func GetLazySingletonSafeInstance(name string) *LazySingletonSafe {
  if lazySingletonSafeInstance == nil {
    // 通过原子操作判断是否执行过来保证并发时的线程安全
    once.Do(func() {
      lazySingletonSafeInstance = &LazySingletonSafe{}
      lazySingletonSafeInstance.name = name
    })
  }
  return lazySingletonSafeInstance
}
