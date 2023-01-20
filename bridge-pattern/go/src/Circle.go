package src

import (
  "fmt"
  "strconv"
)

// 具体业务实体类，实现了Shape接口，跟工具类解耦
type Circle struct {
  Name     string
  drawTool DrawTool
  // 匿名聚合父类，模拟继承RefinedShape
  *RefinedShape
}

// 覆盖父类同名方法
func (c *Circle) SetDrawTool(drawTool DrawTool) {
  fmt.Println("Circle::SetDrawTool() [drawTool.Name=" + drawTool.GetName() + "]")
  c.drawTool = drawTool
}

func (c *Circle) GetDrawTool() DrawTool {
  return c.drawTool
}

func (c *Circle) Draw(x int, y int, radius int) {
  fmt.Println("Circle::Draw() [x=" + strconv.Itoa(x) +
    " y=" + strconv.Itoa(y) + " radius=" + strconv.Itoa(radius) + "]")
  // 通过工具类实现具体功能
  if c.drawTool != nil {
    c.drawTool.DrawStyle()
  }
}
