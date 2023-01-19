package src

import (
  "fmt"
)

type Application struct {
}

func (a *Application) MakeIPhone() {
  var director = new(Director)
  // 创建手机
  var phoneBuilder = new(PhoneBuilder)
  director.BuildIPhone(phoneBuilder)
  var iPhone = phoneBuilder.GetProduct()
  fmt.Println("iPhone:"+iPhone.GetName()+" | ", iPhone)

  // 创建手册
  var manualBuilder = new(ManualBuilder)
  director.BuildIPhone(manualBuilder)
  var manual = manualBuilder.GetProduct()
  fmt.Println("manual:"+manual.GetName()+" | ", manual)
}

func (a *Application) MakeHuaweiPhone() {
  var director = new(Director)

  // 创建手机
  var phoneBuilder = new(PhoneBuilder)
  director.BuildHuaweiPhone(phoneBuilder)
  var huaweiPhone = phoneBuilder.GetProduct()
  fmt.Println(
    "huaweiPhone:"+huaweiPhone.GetName()+" | ", huaweiPhone)

  // 创建手册
  var manualBuilder = new(ManualBuilder)
  director.BuildHuaweiPhone(manualBuilder)
  var manual = manualBuilder.GetProduct()
  fmt.Println("manual:"+manual.GetName()+" | ", manual)
}
