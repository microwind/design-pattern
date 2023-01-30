package main

import (
  "fmt"

  "microwind/src"
)

// main包下的main入口方法
func main() {
  fmt.Println("test start:")
  /**
   * 桥接模式是将基础抽象类作为桥接器，用来连接抽象对象和具体动作，将两者充分解耦。
   * 抽象对象和具体动作都有自己的父类或接口，其中抽象对象以基础抽象类为父类，实现约定的方法。
   * 具体对象以抽象对象为父类，实现父类方法，具体动作也有统一的接口，为抽象对象服务。
   * 使用时，通过抽象对象声明具体对象，再传入具体行为，使得具体对象可以使用具体动作。
   */
  // 声明具体对象，并指定具体工具
  var circle = &src.Circle{
    Name: "circle1",
    // 传递父类
    RefinedShape: &src.RefinedShape{
      Name: "RefinedShape1",
    },
  }
  circle.SetDrawTool(&src.DrawStyleA{
    Name: "DrawStyleA1",
  })
  // 调用对象的方法，里面执行了工具类的方法
  circle.Draw(10, 20, 50)
  // 还可以调用父类里的方法
  circle.DrawDone(circle)

  // /*********************** 分割线 ******************************************/

  // 声明具体对象，并指定另外的工具
  var circle2 = new(src.Circle)
  circle2.SetDrawTool(&src.DrawStyleB{
    Name: "DrawStyleB1",
  })
  // 调用对象的方法，里面执行了工具类的方法
  circle2.Draw(11, 22, 33)
  // 还可以调用父类里的方法
  circle2.DrawDone(circle2)
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
