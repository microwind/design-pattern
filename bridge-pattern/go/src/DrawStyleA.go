package src

import (
  "fmt"
)

// 画圆A，实现了图画基础API
type DrawStyleA struct {
  Name string
}

func (d *DrawStyleA) GetName() string {
  return d.Name
}

func (d *DrawStyleA) DrawStyle() {
  fmt.Println("DrawStyleA::DrawStyle()")
}
