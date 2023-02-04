package src

// 定义抽象形状类，关联图形操作接口，相当于桥接
type AbstractShape interface {
  SetDrawTool(drawTool DrawTool)
  GetDrawTool() DrawTool
  Draw(x int, y int, radius int)
}
