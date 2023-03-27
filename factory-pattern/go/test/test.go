package main

import (
  "fmt"

  "microwind/src"
)

// main包下的main入口方法
func main() {
  fmt.Println("test start:")

  /**
   * 工厂模式由工厂类提供统一的创建对象的方法，省去直接new，而是通过统一方法来创建。
   * 这样的好处就是让对象创建和调用解耦，便于在创建对象时统一干预。
   */
  var vehicleFactory = new(src.VehicleFactory)

  // 获取Bus对象，并调用它的 run 方法
  var bus = vehicleFactory.GetVehicle(src.VehicleType_BUS)
  bus.Run()

  // 获取Car对象，并调用它的 run 方法
  var car = vehicleFactory.GetVehicle(src.VehicleType_CAR)
  car.Run()

  // 获取Motorcycle对象，并调用它的 run 方法
  var motorcycle = vehicleFactory.GetVehicle(src.VehicleType_MOTORCYCLE)
  motorcycle.Run()

  // 获取Van对象，并调用它的 run 方法
  var van = vehicleFactory.GetVehicle(src.VehicleType_VAN)
  van.Run()
}

/**
jarry@jarrys-MacBook-Pro go % go build src/*.go
jarry@jarrys-MacBook-Pro go % go run test/test.go
test start:
Bus::Run().
Car::Run().
Motorcycle::Run().
Van::Run().
*/
