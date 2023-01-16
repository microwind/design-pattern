package src

import "fmt"

type Circle struct {
  // 匿名方式聚合父类
  ShapeBase
}

func (c *Circle) Draw() {
  fmt.Println("Circle::Draw()")
}

func (c *Circle) SetColor(color string) {
  c.color = color
}
