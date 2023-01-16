package src

import "fmt"

type Square struct {
  // 匿名方式聚合父类
  ShapeBase
}

func (c *Square) Draw() {
  fmt.Println("Square::Draw()")
}
