package src

import "fmt"

// 具体装饰器1，实现基础装饰器接口
type RedShapeDecorator struct {
  DecoratedShape Shape
}

func (r *RedShapeDecorator) Draw() {
  r.DecoratedShape.Draw()
  r.SetRedColor(r.DecoratedShape)
}

func (r *RedShapeDecorator) SetRedColor(decoratedShape Shape) {
  fmt.Println("RedShapeDecorator::setRedColor() " + decoratedShape.GetName())
}
