package src

// 图形操作基础接口
type DrawTool interface {
  GetName() string
  DrawStyle()
}
