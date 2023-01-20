package vehicle

import (
  "fmt"
)

// 具体产品实现类
type Bus struct {
  Name string
}

func (b Bus) GetName() string {
  return b.Name
}

func (b *Bus) Run() {
  fmt.Println("Bus::Run() [Name=" + b.Name + "]")
}
