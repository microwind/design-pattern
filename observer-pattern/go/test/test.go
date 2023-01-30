package main

import (
	"fmt"

	"microwind/src"
)

// main包下的main入口方法
func main() {
  fmt.Println("test start:")
  /**
   * 观察者模式应用非常广泛，主要是观察者提前绑定到发布者
   * 当发布者发布消息时，批量广播通知，而无需逐一通知
   * 观察者监听到消息后自己决定采取哪一种行为
   */

  // 定义一个主题，也就是发布者
  var concreteSubject = new(src.ConcreteSubject)
  // 初始化主题
  concreteSubject.Init("concreteSubject")
  var observer1 = &src.ConcreteObserver{}
  // 再声明观察者，通Init注册到主题上
  observer1.Init(concreteSubject, "observer1")

  /**************************************************************/

  // 也可以单独给主题注册一个新的观察者
  var observer2 = &src.ConcreteObserver2{}
  observer2.SetName("observer2")
  // 可以不给观察者绑定某个主题，而是仅从客户角度注册观察者
  // observer2.SetSubject(concreteSubject)

  concreteSubject.Register(observer2)

  // 可以移除观察者对象，打开注释试下
  // concreteSubject.Remove(observer2)

  // 主题开始发布新通知，各观察者自动更新
  concreteSubject.Notify("hello, this is broadcast.")
}

/**
jarry@jarrys-MacBook-Pro go % go build src/*.go
jarry@jarrys-MacBook-Pro go % go run test/test.go
test start:
concreteSubject::Register() [observer.name = observer1]
concreteSubject::Register() [observer.name = observer2]
concreteSubject::Notify() [content = hello, this is broadcast.]
ConcreteObserver::Update() [subject.name = concreteSubject content = hello, this is broadcast.]
ConcreteObserver2::Update() [subject.name = unknow content = hello, this is broadcast.]
*/
