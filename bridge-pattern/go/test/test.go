package main

import (
  "fmt"

  "microwind/src"
)

// main包下的main入口方法
func main() {
  fmt.Println("test start:")
  /**
   * 桥接模式是将基础抽象类作为桥接器，用来连接业务对象和具体动作，将两者充分解耦。
   * 具体对象以抽象对象为父类，实现父类方法。
   * 具体工具类实现统一的工具接口，为抽象桥接对象服务
   * 使用时，声明具体对象同时传入具体工具，使得具体对象可以使用具体工具的动作。
   */
  // 声明具体对象，并指定具体工具
  var shape = &src.RefinedShape{
    Name: "shape1",
  }
  shape.SetDrawTool(&src.DrawStyleA{
    Name: "DrawStyleA1",
  })
  // 调用对象的方法，里面执行了工具类的方法
  shape.Draw(10, 20, 50)
  // 调用具体类的扩充方法
  shape.DrawDone(shape)

  // /*********************** 分割线 ******************************************/

  // 声明具体对象，并指定另外的工具
  var shape2 = new(src.RefinedShape)
  shape2.SetDrawTool(&src.DrawStyleB{
    Name: "DrawStyleB1",
  })
  // 调用对象的方法，里面执行了工具类的方法
  shape2.Draw(11, 22, 33)
  // 调用具体类的扩充方法
  shape2.DrawDone(shape2)
}

/**
jarry@jarrys-MacBook-Pro go % go build src/*.go
jarry@jarrys-MacBook-Pro go % go run test/test.go
test start:
Circle::SetDrawTool() [drawTool.Name=DrawStyleA1]
Circle::Draw() [x=10 y=20 radius=50]
DrawStyleA::DrawStyle()
RefinedShape::DrawDone(), 执行的DrawTool是:  &{DrawStyleA1}
Circle::SetDrawTool() [drawTool.Name=DrawStyleB1]
Circle::Draw() [x=11 y=22 radius=33]
DrawStyleB::DrawStyle()
RefinedShape::DrawDone(), 执行的DrawTool是:  &{DrawStyleB1}
*/
