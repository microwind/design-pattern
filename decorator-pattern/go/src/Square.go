package src

import "fmt"

// 具体形状实现了基础形状接口
type Square struct {
}

func (c *Square) Draw() {
  fmt.Println("Square::Draw()")
}

func (c *Square) GetName() string {
  return "Square"
}
