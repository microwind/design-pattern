import { VehicleType } from '../src/VehicleFactory.js'
import { FactoryCreator } from '../src/FactoryCreator.js'

export function test() {
  /**
   * 抽象工厂就是把生产产品的工厂也根据统一的抽象工厂来创建，
   * 这样不同类型的工厂可以在统一的约束下，整体上看更新加清晰。
   * 当声明工厂时可以通过抽象类型或具体工厂来声明，然后依据工厂来生产不同的产品。
   */

  // 通过工厂建造类获得指定工厂
  const vehicleFactory = FactoryCreator.getFactory('vehicle')

  // 获取Bus对象，并调用它的 run 方法
  const bus = vehicleFactory.getVehicle(VehicleType.BUS)
  bus.run()

  // 获取Car对象，并调用它的 run 方法
  const car = vehicleFactory.getVehicle(VehicleType.CAR)
  car.run()

  // 获取Motorcycle对象，并调用它的 run 方法
  const motorcycle = vehicleFactory.getVehicle(VehicleType.MOTORCYCLE)
  motorcycle.run()

  // 获取Motorcycle对象，并调用它的 run 方法
  const van = vehicleFactory.getVehicle(VehicleType.VAN)
  van.run()

  // /*********************** 分割线 ******************************************/

  // 声明商店工厂
  const shopFactory = FactoryCreator.getFactory('shop')
  // 从商店工厂获取商店对象
  const shop = shopFactory.getShop('SupermarketShop')
  // 调用商店的方法
  shop.greetings()

  // /*********************** 分割线 ******************************************/

  // 再声明一个商店工厂
  const shopFactory2 = FactoryCreator.getFactory('shop')
  const directSaleShop = shopFactory2.getShop('DirectSaleShop')
  directSaleShop.greetings()
  // 调用自己独立的方法
  directSaleShop.welcome()
}

// 执行测试
;(function () {
  console.log('test start:')
  test()
})()

/*
// node run
jarry@jarrys-MacBook-Pro js % node -v
v14.17.0
jarry@jarrys-MacBook-Pro js % node test/test.js
test start:
Bus::run().
Car::run().
Motorcycle::run().
Van::run().
SupermarketShop::greetings
DirectSaleShop::greetings
DirectSaleShop::Welcome
*/

/*
// npm run
jarry@jarrys-MacBook-Pro js % pwd
/Users/jarry/github/design-pattern/abstract-factory/js
jarry@jarrys-MacBook-Pro js % npm run test

> esm-project@1.0.0 test
> node test/test.js

test start:
Bus::run().
Car::run().
Motorcycle::run().
Van::run().
SupermarketShop::greetings
DirectSaleShop::greetings
Shop::Welcome
*/

/**
// n run
jarry@jarrys-MacBook-Pro js % n run 14.17.0 test/test.js
test start:
Bus::run().
Car::run().
Motorcycle::run().
Van::run().
SupermarketShop::greetings
DirectSaleShop::greetings
Shop::Welcome
*/
