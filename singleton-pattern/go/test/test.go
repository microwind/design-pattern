package main

import (
  "fmt"

  "../src"
)

// main包下的main入口方法
func main() {
  fmt.Println("test start:")
  /**
   * 单例模式就是一个类只创建一个实例，以便节省开销和保证统一
   * 对于多线程语言需要注意线程安全和性能之间取得一个平衡
   */

  // 懒汉模式，调用函数时实例化
  var lazySingleton1 = src.GetLazySingletonInstance("lazySingleton1")
  var lazySingleton2 = src.GetLazySingletonInstance("lazySingleton2")
  lazySingleton1.Run()
  // 实例相同
  lazySingleton2.Run()

  // 懒汉模式，线程安全
  var lazySingletonSafe1 = src.GetLazySingletonSafeInstance("lazySingletonSafe1")
  lazySingletonSafe2 := src.GetLazySingletonSafeInstance("lazySingletonSafe2")
  lazySingletonSafe1.Run()
  // 实例相同
  lazySingletonSafe2.Run()

  // 双重检查机制，并发加锁
  var doubleCheckSingleton1 = src.GetDoubleCheckSingletonInstance("doubleCheckSingleton1")
  doubleCheckSingleton2 := src.GetDoubleCheckSingletonInstance("doubleCheckSingleton2")
  doubleCheckSingleton1.Run()
  // 实例相同
  doubleCheckSingleton2.Run()

  // 饿汉模式，在main里直接初始化，这样就可以获得唯一实例
  src.EagerSingletonInit()
  var eagerSingleton1 = src.GetEagerSingleton("eagerSingleton1")
  var eagerSingleton2 = src.GetEagerSingleton("eagerSingleton2")
  eagerSingleton1.Run()
  // 实例相同
  eagerSingleton2.Run()
}

/**
jarry@jarrys-MacBook-Pro go % go build src/*.go
jarry@jarrys-MacBook-Pro go % go run test/test.go
test start:
LazySingleton::run() lazySingleton1
LazySingleton::run() lazySingleton1
LazySingletonSafe::run() lazySingletonSafe1
LazySingletonSafe::run() lazySingletonSafe1
DoubleCheckSingleton::run() doubleCheckSingleton1
DoubleCheckSingleton::run() doubleCheckSingleton1
EagerSingleton::run() eagerSingleton1
EagerSingleton::run() eagerSingleton1
*/
