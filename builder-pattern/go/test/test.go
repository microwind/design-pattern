package main

import (
  "fmt"

  "microwind/src"
)

// main包下的main入口方法
func main() {
  fmt.Println("test start:")
  /**
   * 建造者模式是使用多个简单的对象一步一步构建出一个复杂的对象来。
   * 分为主管类和建造这类，主管类负责具体指挥调度，建造负责具体实施。
   * 主管类通过一步一步调用各种建造者实现复杂对象。
   */
  var Application = &src.Application{}
  Application.MakeIPhone()

  Application.MakeHuaweiPhone()

  // *********************** 分割线 ******************************************/

  // 声明指挥者
  var director = new(src.Director)
  // 创建手机
  var phoneBuilder = new(src.PhoneBuilder)
  director.BuildMiPhone(phoneBuilder)
  var miPhone = phoneBuilder.GetProduct()
  fmt.Println("miPhone:"+miPhone.GetName()+" | ", miPhone)
  // 创建手册
  var manualBuilder = new(src.ManualBuilder)
  director.BuildMiPhone(manualBuilder)
  var manual = manualBuilder.GetProduct()
  fmt.Println("manual:"+manual.GetName()+" | ", manual)
}

/**
jarry@jarrys-MacBook-Pro go % go build src/*.go
jarry@jarrys-MacBook-Pro go % go run test/test.go
test start:
iPhone:iPhone |  &{iPhone [120 500] 100}
manual:iPhone |  &{iPhone [120 500] 100}
huaweiPhone:HuaweiPhone |  &{HuaweiPhone [140 600] 102}
manual:HuaweiPhone |  &{HuaweiPhone [140 600] 102}
miPhone:MiPhone |  &{MiPhone [130 550] 103}
manual:MiPhone |  &{MiPhone [130 550] 103}
*/
