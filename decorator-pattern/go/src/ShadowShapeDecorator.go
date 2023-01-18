package src

import "fmt"

// 具体装饰器2，实现基础装饰器接口
type ShadowShapeDecorator struct {
  DecoratedShape Shape
}

func (s *ShadowShapeDecorator) Draw() {
  // 装饰器根据需要是否调用形状的Draw方法
  // s.DecoratedShape.Draw()
  s.SetShadow(s.DecoratedShape)
}

func (s *ShadowShapeDecorator) SetShadow(decoratedShape Shape) {
  fmt.Println("ShadowShapeDecorator::SetShadow() " + decoratedShape.GetName())
}
