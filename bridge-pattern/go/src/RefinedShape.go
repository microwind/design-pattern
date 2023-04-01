package src

import (
  "fmt"
  "strconv"
)

// 具体桥接类，继承抽象桥接类，扩充了自己的方法
// 也可以将此类当做抽象类，再往下派生具体实现类
type RefinedShape struct {
  Name     string
  drawTool DrawTool
}

// 设置具体工具类
func (c *RefinedShape) SetDrawTool(drawTool DrawTool) {
  fmt.Println("RefinedShape::SetDrawTool() [drawTool.Name=" + drawTool.GetName() + "]")
  c.drawTool = drawTool
}

func (c *RefinedShape) GetDrawTool() DrawTool {
  return c.drawTool
}

func (c *RefinedShape) Draw(x int, y int, radius int) {
  fmt.Println("RefinedShape::Draw() [x=" + strconv.Itoa(x) +
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
