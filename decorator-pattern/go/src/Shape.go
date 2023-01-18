package src

// 基础形状类，可定义公共方法
type Shape interface {
  Draw()
  GetName() string
}
