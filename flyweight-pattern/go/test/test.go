package main

import (
  "fmt"

  "microwind/src"
)

// main包下的main入口方法
func main() {
  fmt.Println("test start:")
  /**
   * 享元模式就是将已经声明过的实例或数据保存在内存里，需要使用时则取出来，无需再次实例化和声明。
   * 通过共享多个对象所共有的相同状态，以达到节省开销的目的。
   * 享元模式分为内部状态和外部状态，内部状态基于享元对象共享，外部状态则外部传入或使用非享元类。
   */

  // 假设有钢琴和吉他，钢琴使用者很多需要共享实例，而吉他每次创建新实例

  // 2个一样名称的为共享对象，只创建1个实例，后面的返回缓存实例
  var FlyweightFactory = new(src.FlyweightFactory)
  var factory1 = FlyweightFactory.GetFactory("piano1")
  var factory2 = FlyweightFactory.GetFactory("piano1")
  var factory3 = FlyweightFactory.GetFactory("piano2")
  var factory4 = FlyweightFactory.GetFactory("piano2")

  factory1.Operate("factory1")
  factory2.Operate("factory2")
  factory3.Operate("factory3")
  factory4.Operate("factory4")

  // 查看一共多少个对象
  for _, flyweight := range FlyweightFactory.GetFactoryPool() {
    fmt.Println("享元对象:" + flyweight.GetName())
  }

  // 无需共享的，名字一样也是多个对象
  var factory5 = src.UnsharedConcreteFlyweightInit("guitar1")
  var factory6 = src.UnsharedConcreteFlyweightInit("guitar1")
  factory5.Operate("factory5")
  factory6.Operate("factory6")
}

/**
jarry@jarrys-MacBook-Pro go % go build src/*.go
jarry@jarrys-MacBook-Pro go % go run test/test.go
test start:
ConcreteFlyweight::Init(name) [创建具体享元piano1]
FlyweightFactory::GetFactory(name) [成功获取具体享元piano1]
ConcreteFlyweight::Init(name) [创建具体享元piano2]
FlyweightFactory::GetFactory(name) [成功获取具体享元piano2]
ConcreteFlyweight::Operate() [ piano1 piano factory1 ]
ConcreteFlyweight::Operate() [ piano1 piano factory2 ]
ConcreteFlyweight::Operate() [ piano2 piano factory3 ]
ConcreteFlyweight::Operate() [ piano2 piano factory4 ]
享元对象:piano2
享元对象:piano1
UnsharedConcreteFlyweight::Init(name) [创建非共享对象guitar1]
UnsharedConcreteFlyweight::Init(name) [创建非共享对象guitar1]
UnsharedConcreteFlyweight::Operate() [ guitar1 guitar factory5 ]
UnsharedConcreteFlyweight::Operate() [ guitar1 guitar factory6 ]
*/
