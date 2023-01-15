package src

import "fmt"

// 懒汉模式单例，延迟实例化，但不是很安全
type LazySingleton struct {
  name string
}

func (s *LazySingleton) Run() {
  fmt.Println("LazySingleton::run()", s.name)
}

// 定义私有变量
var lazySingleton *LazySingleton

// Golang不支持静态方法，可用外部func代替
func GetLazySingletonInstance(name string) *LazySingleton {
  // 并发很多情况下，不同线程可能会创建多个实例
  if lazySingleton == nil {
    lazySingleton = &LazySingleton{}
    lazySingleton.name = name
  }
  return lazySingleton
}
