package src

import (
  "fmt"
)

// 画圆B，实现了图画基础API
type DrawStyleB struct {
  Name string
}

func (d *DrawStyleB) GetName() string {
  return d.Name
}

func (d *DrawStyleB) DrawStyle() {
  fmt.Println("DrawStyleB::DrawStyle()")
}
