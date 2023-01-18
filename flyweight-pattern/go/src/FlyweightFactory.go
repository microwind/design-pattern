package src

import "fmt"

// 享元工厂，储存一个对象共享池，已经生成过的对象直接取出
type FlyweightFactory struct {
}

// 定义公共map用作共享池子
var FlyweightFactoryPool = make(map[string]Flyweight)

// 享元对象实例化函数，仅内部调用
func concreteFlyweightInit(name string) Flyweight {
  fmt.Println("ConcreteFlyweight::Init(name) [创建具体享元" + name + "]")
  return &ConcreteFlyweight{
    name: name,
    kind: "piano",
  }
}

// 非享元对象首字母大写，可以对外
func UnsharedConcreteFlyweightInit(name string) Flyweight {
  fmt.Println("UnsharedConcreteFlyweight::Init(name) [创建非共享对象" + name + "]")
  return &UnsharedConcreteFlyweight{
    name: name,
    kind: "guitar",
  }
}

// 这里的name可以认为是内部状态，在构造时确定，具有唯一性。
func (f *FlyweightFactory) GetFactory(name string) Flyweight {
  pool := FlyweightFactoryPool
  var flyweight = pool[name]
  if flyweight == nil {
    // 如果对象不存在则创建新的对象放入到池子里，如果已经存在则复用前面的对象
    flyweight = concreteFlyweightInit(name)
    pool[name] = flyweight
  } else {
    fmt.Println("FlyweightFactory::GetFactory(name) [成功获取具体享元" + name + "]")
  }
  return flyweight
}

func (f *FlyweightFactory) GetFactoryPool() map[string]Flyweight {
  return FlyweightFactoryPool
}
