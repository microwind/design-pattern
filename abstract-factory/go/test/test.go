package main

import (
  "fmt"

  "microwind/src"
  "microwind/src/shop"
)

// main包下的main入口方法
func main() {
  fmt.Println("test start:")
  /**
   * 抽象工厂就是把生产产品的工厂也根据统一的抽象工厂来创建，
   * 这样不同类型的工厂可以在统一的约束下，整体上看更新加清晰。
   * 当声明工厂时可以通过抽象类型或具体工厂来声明，然后依据工厂来生产不同的产品。
   */

  // 通过工厂建造类获得指定工厂
  var FactoryCreator = &src.FactoryCreator{}
  var vehicleFactory = FactoryCreator.GetFactory("vehicle")

  // 获取Bus对象，并调用它的 run 方法
  var bus = vehicleFactory.GetVehicle(src.VehicleType_BUS, "bus")
  bus.Run()

  // 获取Car对象，并调用它的 run 方法
  var car = vehicleFactory.GetVehicle(src.VehicleType_CAR, "car")
  car.Run()

  // 获取Motorcycle对象，并调用它的 run 方法
  var motorcycle = vehicleFactory.GetVehicle(src.VehicleType_MOTORCYCLE, "motorcycle")
  motorcycle.Run()

  // 获取Motorcycle对象，并调用它的 run 方法
  var van = vehicleFactory.GetVehicle(src.VehicleType_VAN, "van")
  van.Run()

  // /*********************** 分割线 ******************************************/

  // 再次声明商店工厂
  var shopFactory = FactoryCreator.GetFactory("shop")
  // 从商店工厂获取商店对象
  var supermarketShop = shopFactory.GetShop("SupermarketShop", "shop")
  // 调用商店的方法
  supermarketShop.Greetings()

  // /*********************** 分割线 ******************************************/

  // 再声明一个商店工厂
  var shopFactory2 = FactoryCreator.GetFactory("shop")
  var directSaleShop = shopFactory2.GetShop("DirectSaleShop", "directSaleShop")
  directSaleShop.Greetings()
  // 直接类型转换失败
  // var directSaleShop1 = shop.DirectSaleShop(directSaleShop)
  // directSaleShop1.Welcome()
  // 通过类型断言实现类型转换
  var directSaleShop1 = directSaleShop.(*shop.DirectSaleShop)
  directSaleShop1.Welcome()
}

/*
jarry@jarrys-MacBook-Pro go % go build src/*.go
jarry@jarrys-MacBook-Pro go % go run test/test.go
test start:
Bus::Run() [Name=bus]
Car::Run() [Name=car]
Motorcycle::Run() [Name=motorcycle]
Van::Run() [Name=van]
SupermarketShop::Greetings [Name=shop]
DirectSaleShop::Greetings [Name=directSaleShop]
DirectSaleShop::Welcome [Name=directSaleShop]
*/
