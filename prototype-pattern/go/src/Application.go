package src

import (
  "fmt"
  "strconv"
)

type Application struct {
  shapes []Shape
}

func (a *Application) Init() {
  a.shapes = make([]Shape, 0, 100)
}

func (a *Application) AddToShapes() {
  circle := &Circle{}
  circle.SetCategory("Circle")
  circle.SetWidth(10)
  circle.SetHeight(20)
  circle.SetColor("red")
  a.shapes = append(a.shapes, circle)

  // 添加Clone
  anotherCircle := circle.Clone()
  anotherCircle.SetColor("pink")
  a.shapes = append(a.shapes, anotherCircle)
  // 变量 `anotherCircle（另一个圆）`与 `circle（圆）`对象的内容完全一样。

  rectangle := &Rectangle{}
  rectangle.SetCategory("Rectangle")
  rectangle.SetWidth(99)
  rectangle.SetHeight(69)
  rectangle.SetColor("green")
  a.AddShape(rectangle)
  // 再添加一个clone
  a.shapes = append(a.shapes, rectangle.Clone())

}

func (a *Application) AddShape(shape Shape) {
  a.shapes = append(a.shapes, shape)
}

func (a *Application) GetShape(index int) Shape {
  return a.shapes[index]
}

func (a *Application) GetShapes() []Shape {
  return a.shapes
}

func (a *Application) GetShapeClone(index int) Shape {
  shape := a.shapes[index]
  if shape != nil {
    return shape.Clone()
  }
  return nil
}

func (a *Application) PrintShapes() {
  for i := 0; i < len(a.shapes); i++ {
    shape := a.shapes[i]
    fmt.Println("shape " + strconv.Itoa(i) + " : " + shape.String())
  }
}
