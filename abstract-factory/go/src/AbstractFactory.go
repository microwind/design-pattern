package src

import (
  "./shop"

  "./vehicle"
)

/*
  意图：提供一个创建一系列相互依赖的接口，而无需指定它们具体的类。
  主要作用：主要解决接口选择的问题。在一个对象家族系统里面里面，抽象定义多个产品对象。
  何时使用：产品很多，形成产品系列，而系统只需要处理其中某一类的产品。
  如何解决：在一个产品系列里面，定义多个产品对象。由抽象类来负责创建产品工厂。
*/

// 抽象工厂类，用来生成具体的工厂。Go里没有抽象类，用接口代替。
type AbstractFactory interface {
  GetVehicle(vehicleType string, name string) vehicle.Vehicle

  GetShop(shopType string, name string) shop.Shop
}
