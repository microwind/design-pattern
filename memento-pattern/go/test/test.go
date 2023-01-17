package main

import (
  "fmt"
  "strconv"

  "../src"
)

// main包下的main入口方法
func main() {
  fmt.Println("test start:")
  /*
   * 备忘录模式是在不暴露对象实现细节的情况下保存和恢复对象之前的状态。
   * 先声明发起人Originator，再声明负责人Caretaker，发起人生成备忘录Memento
   * 通过负责人则保存备忘录历史记录，读取备忘录由负责人来完成。
   */
  var originator = &src.Originator{}
  var careTaker = new(src.Caretaker)
  // 发起人产生一个状态
  originator.SetState("state1")
  // 覆盖了状态，那么前面的状态未保存
  originator.SetState("state2")
  // 发起人生成备忘录，一般添加时直接保存即可
  var memento = originator.SaveMemento()
  // 负责人保添加备忘录历史记录
  careTaker.Add(memento)

  // 直接生成备忘录并添加到负责人的备忘录列表
  originator.SetState("state3")
  careTaker.Add(originator.SaveMemento())
  originator.SetState("state4")
  careTaker.Add(originator.SaveMemento())

  fmt.Println("发起人当前的状态: " + originator.GetState())

  // 发起人通过负责人那里取出状态
  originator.RestoreMemento(careTaker.Get(0))
  fmt.Println("第一个保存的状态: " + originator.GetState())
  originator.RestoreMemento(careTaker.Get(1))
  fmt.Println("第二个保存的状态: " + originator.GetState())

  // 遍历全部备忘录
  for i := 0; i < len(careTaker.GetMementoList()); i++ {
    // 外部一般不直接访问备忘录里面的状态，而是逐个恢复备忘录，再取出状态来
    originator.RestoreMemento(careTaker.Get(i))
    fmt.Println("state: " + strconv.Itoa(i) + ")" + originator.GetState())
  }
}

/**
jarry@jarrys-MacBook-Pro go % go build src/*.go
jarry@jarrys-MacBook-Pro go % go run test/test.go
test start:
Originator::SaveMemento() [state = state2]
Memento::Memento() [state = state2]
Caretaker::Add() [memento = Memento]
Originator::SaveMemento() [state = state3]
Memento::Memento() [state = state3]
Caretaker::Add() [memento = Memento]
Originator::SaveMemento() [state = state4]
Memento::Memento() [state = state4]
Caretaker::Add() [memento = Memento]
发起人当前的状态: state4
第一个保存的状态: state2
第二个保存的状态: state3
state: 0)state2
state: 1)state3
state: 2)state4
*/
