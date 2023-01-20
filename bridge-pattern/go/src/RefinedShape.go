package src

import "fmt"

// 定义新抽象类继承基础抽象类，用于子类聚合
type RefinedShape struct {
  Name string
}

// 新抽象类里的方法，可作为补充
func (r *RefinedShape) DrawDone(shape Shape) {
  fmt.Println("RefinedShape::DrawDone(), 执行的DrawTool是: ", shape.GetDrawTool())
}
