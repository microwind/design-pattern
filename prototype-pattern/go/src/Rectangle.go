package src

import "fmt"

type Rectangle struct {
  // 匿名方式聚合父类
  ShapeBase
}

func (c *Rectangle) Draw() {
  fmt.Println("Rectangle::Draw()")
}
