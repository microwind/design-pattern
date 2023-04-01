package src

// 定义抽象的Shape接口，关联具体的DrawTool操作接口，桥接具体的Shape实现与DrawTool实现
type AbstractShape interface {
  SetDrawTool(drawTool DrawTool)
  GetDrawTool() DrawTool
  Draw(x int, y int, radius int)
}
