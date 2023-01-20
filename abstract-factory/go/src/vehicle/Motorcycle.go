package vehicle

import (
  "fmt"
)

// 具体产品实现类
type Motorcycle struct {
  Name string
}

func (m Motorcycle) GetName() string {
  return m.Name
}

func (m *Motorcycle) Run() {
  fmt.Println("Motorcycle::Run() [Name=" + m.Name + "]")
}
