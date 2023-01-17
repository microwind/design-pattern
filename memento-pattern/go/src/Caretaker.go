package src

import "fmt"

// 负责人(Caretaker)角色，只负责保存备忘录记录，不能修改备忘录对象的内容
type Caretaker struct {
  mementoList []*Memento
}

func (c *Caretaker) Add(memento *Memento) {
  fmt.Println("Caretaker::Add() [memento = " + memento.GetName() + "]")
  if c.mementoList == nil {
    // c.mementoList = make([]*Memento, 0, 100)
    c.mementoList = make([]*Memento, 0)
  }
  c.mementoList = append(c.mementoList, memento)
}

func (c *Caretaker) Get(index int) *Memento {
  return c.mementoList[index]
}

func (c *Caretaker) GetMementoList() []*Memento {
  return c.mementoList
}
