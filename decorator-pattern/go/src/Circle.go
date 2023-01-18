package src

import "fmt"

// 具体形状实现了基础形状接口
type Circle struct {
}

func (c *Circle) Draw() {
  fmt.Println("Circle::Draw()")
}

func (c *Circle) GetName() string {
  return "Circle"
}
