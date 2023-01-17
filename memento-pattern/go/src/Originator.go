package src

import "fmt"

// 发起人(Originator)负责生成状态快照，即利用一个新备忘录对象将自己的内部状态存储起来
type Originator struct {
  state string
}

// 每次创建一个新备忘录来保存状态
func (o *Originator) SaveMemento() *Memento {
  fmt.Println("Originator::SaveMemento() [state = " + o.state + "]")
  // 直接返回新备忘录实体
  // return &Memento{
  //   state: o.state,
  // }

  // 或调用Init方法
  m := &Memento{}
  m.Init(o.state)
  return m
}

// 从备忘录中恢复状态
func (o *Originator) RestoreMemento(memento *Memento) {
  o.state = memento.GetState()
}

func (o *Originator) GetState() string {
  return o.state
}

func (o *Originator) SetState(state string) {
  o.state = state
}
