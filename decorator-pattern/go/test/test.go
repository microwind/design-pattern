package main

import (
  "fmt"

  "../src"
)

// main包下的main入口方法
func main() {
  fmt.Println("test start:")

  /**
   * 装饰器模式是将一个对象放到一个装饰器对象中，执行装饰器类里的方法时，对象的行为能力得到增强。
   * 先声明具体对象，然后放到装饰器，得到一个带有装饰器的新对象，该对象具备了新的能力。
   */

  // 声明形状
  var circle = new(src.Circle)
  var square = new(src.Square)

  // 增加红色装饰
  var redCircle = &src.RedShapeDecorator{
    DecoratedShape: circle,
  }
  var redSquare = &src.RedShapeDecorator{
    DecoratedShape: square,
  }
  circle.Draw()
  redCircle.Draw()
  redSquare.Draw()

  // 增加影子装饰
  var shadowCircle = &src.ShadowShapeDecorator{
    DecoratedShape: circle,
  }
  var shadowSquare = &src.ShadowShapeDecorator{
    DecoratedShape: square,
  }
  shadowCircle.Draw()
  shadowSquare.Draw()
}

/**
jarry@jarrys-MacBook-Pro go % go build src/*.go
jarry@jarrys-MacBook-Pro go % go run test/test.go
test start:
Circle::Draw()
Circle::Draw()
RedShapeDecorator::setRedColor() Circle
Square::Draw()
RedShapeDecorator::setRedColor() Square
ShadowShapeDecorator::SetShadow() Circle
ShadowShapeDecorator::SetShadow() Square
*/
