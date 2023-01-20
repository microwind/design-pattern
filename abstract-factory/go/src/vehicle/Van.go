package vehicle

import (
  "fmt"
)

// 具体产品实现类
type Van struct {
  Name string
}

func (v Van) GetName() string {
  return v.Name
}

func (v *Van) Run() {
  fmt.Println("Van::Run() [Name=" + v.Name + "]")
}
