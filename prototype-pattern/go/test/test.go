package main

import (
	"fmt"

	"microwind/src"
)

// main包下的main入口方法
func main() {
  fmt.Println("test start:")
  /**
   * 原型模式主要就是复制已有的对象，而无需实例化类，从而提升实例化对象时的性能
   * 其实就是复制实例的属性到新对象上，减少了执行构造的步骤。
   */
  var application = &src.Application{}
  application.Init()
  application.AddToShapes()
  var shapeClone = application.GetShapeClone(0)
  // SetColor需要接口中定义
  shapeClone.SetColor("gray")
  fmt.Println("shapeClone : " + shapeClone.String())
  // 直接更改
  // application.GetShape(3).SetColor("yellow")
  application.PrintShapes()

  /*********************** 分割线 ******************************************/
  // 追加一个Squre实例
  application.AddShape(&src.Square{})
  // 打不打印查看结果
  for _, shape := range application.GetShapes() {
    shape.Draw()
    fmt.Println(shape.String())
  }
}

/**
jarry@jarrys-MacBook-Pro go % go build src/*.go
jarry@jarrys-MacBook-Pro go % go run test/test.go
test start:
shapeClone : {width = 10, height = 20, category = Circle[clone], color = gray}
shape 0 : {width = 10, height = 20, category = Circle, color = red}
shape 1 : {width = 10, height = 20, category = Circle[clone], color = pink}
shape 2 : {width = 99, height = 69, category = Rectangle, color = green}
shape 3 : {width = 99, height = 69, category = Rectangle[clone], color = green}
Circle::Draw()
{width = 10, height = 20, category = Circle, color = red}
ShapeBase::Draw()
{width = 10, height = 20, category = Circle[clone], color = pink}
Rectangle::Draw()
{width = 99, height = 69, category = Rectangle, color = green}
ShapeBase::Draw()
{width = 99, height = 69, category = Rectangle[clone], color = green}
Square::Draw()
{width = 0, height = 0, category = , color = }
*/
