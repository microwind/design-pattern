package src

// 定义形状接口，其他形状实现该接口
type Shape interface {
  Draw()
  Clone() Shape
  String() string
  SetColor(color string)
}
