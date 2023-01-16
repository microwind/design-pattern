package src

import (
  "fmt"
)

// 定义了Shape作为基础接口，以便各形状有统一类型
// 再把公共方法都放到ShapeBase中，作为父类供各种形状继承
type ShapeBase struct {
  width    int
  height   int
  color    string
  category string
}

// 本来是抽象方法，供子类覆盖，但Go没有抽象方法
// 故这里只是为了实现接口而已，没其他用处
func (s *ShapeBase) Draw() {
  fmt.Println("ShapeBase::Draw()")
}

func (s *ShapeBase) SetWidth(width int) {
  s.width = width
}

func (s *ShapeBase) GetWidth() int {
  return s.width
}

func (s *ShapeBase) GetHeight() int {
  return s.height
}

func (s *ShapeBase) SetHeight(height int) {
  s.height = height
}

func (s *ShapeBase) SetColor(color string) {
  s.color = color
}

func (s *ShapeBase) GetColor() string {
  return s.color
}

func (s *ShapeBase) SetCategory(category string) {
  s.category = category
}

// 将指针指向同一内存的方式来实现clone
func (s *ShapeBase) Clone() Shape {
  copy := *s
  copy.SetCategory(copy.category + "[clone]")
  return &copy
}

// 逐个复制属性来克隆
// func (s *ShapeBase) Clone() Shape {
//   return &ShapeBase{
//     width:    s.width,
//     height:   s.height,
//     color:    s.color,
//     category: s.category + "(clone)",
//   }
// }

func (s *ShapeBase) String() string {
  return fmt.Sprintf(`{width = %d, height = %d, category = %s, color = %s}`,
    s.width, s.height, s.category, s.color)
}
