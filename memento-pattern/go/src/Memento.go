package src

import "fmt"

// 备忘录(Memento)角色，负责存储发起人传入的状态
type Memento struct {
  name  string
  state string
}

func (m *Memento) Init(state string) {
  m.name = "Memento"
  fmt.Println("Memento::Memento() [state = " + state + "]")
  m.SetState(state)
}

func (m *Memento) GetState() string {
  return m.state
}

func (m *Memento) SetState(state string) {
  m.state = state
}

func (m *Memento) GetName() string {
  return m.name
}
