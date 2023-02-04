package src

import (
  "fmt"
  "strconv"
)

// 定义新抽象类继承基础抽象类，用于子类聚合
type RefinedShape struct {
  Name     string
  drawTool DrawTool
}

// 设置具体工具类
func (c *RefinedShape) SetDrawTool(drawTool DrawTool) {
  fmt.Println("Circle::SetDrawTool() [drawTool.Name=" + drawTool.GetName() + "]")
  c.drawTool = drawTool
}

func (c *RefinedShape) GetDrawTool() DrawTool {
  return c.drawTool
}

func (c *RefinedShape) Draw(x int, y int, radius int) {
  fmt.Println("Circle::Draw() [x=" + strconv.Itoa(x) +
    " y=" + strconv.Itoa(y) + " radius=" + strconv.Itoa(radius) + "]")
  // 通过工具类实现具体功能
  if c.drawTool != nil {
    c.drawTool.DrawStyle()
  }
}

// 新方法，可作为具体工具的补充
func (r *RefinedShape) DrawDone(shape AbstractShape) {
  fmt.Println("RefinedShape::DrawDone(), 执行的DrawTool是: ", shape.GetDrawTool())
}
