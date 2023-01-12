import { VehicleType, VehicleFactory } from '../src/VehicleFactory.js'
import { FactoryCreator, FactoryType } from '../src/FactoryCreator.js'
import { DirectSaleShop } from '../src/shop/DirectSaleShop.js'

export function test() {

  /**
   * 抽象工厂就是把生产产品的工厂也根据统一的抽象工厂来创建，
   * 这样不同类型的工厂可以在统一的约束下，整体上看更新加清晰。
   * 当声明工厂时可以通过抽象类型或具体工厂来声明，然后依据工厂来生产不同的产品。
   */

  // 通过工厂建造类获得指定工厂
  const vehicleFactory = FactoryCreator.getFactory('vehicle')

  // 获取Bus对象，并调用它的 run 方法
  if (!vehicleFactory) {
    return
  }
  const bus = vehicleFactory.getVehicle(VehicleType.BUS)
  bus && bus.run()

  // 获取Car对象，并调用它的 run 方法
  const car = vehicleFactory.getVehicle(VehicleType.CAR)
  car && car.run()

  // 获取Motorcycle对象，并调用它的 run 方法
  const motorcycle = vehicleFactory.getVehicle(VehicleType.MOTORCYCLE)
  motorcycle && motorcycle.run()

  // 获取Motorcycle对象，并调用它的 run 方法
  const van = vehicleFactory.getVehicle(VehicleType.VAN)
  van && van.run()

  // /*********************** 分割线 ******************************************/

  // 声明商店工厂
  const shopFactory = FactoryCreator.getFactory('shop')
  // 从商店工厂获取商店对象
  const shop = shopFactory && shopFactory.getShop('SupermarketShop', {})
  // 调用商店的方法
  shop && shop.greetings()

  // /*********************** 分割线 ******************************************/

  // 再声明一个商店工厂
  const shopFactory2 = FactoryCreator.getFactory('shop')
  const directSaleShop = shopFactory2 && shopFactory2.getShop('DirectSaleShop', {})
  if (directSaleShop) {
    directSaleShop.greetings()
    // 这里返回的是接口Shop，而接口并并没有welcome方法，故需要类型强转
    // const directSaleShop2 = directSaleShop as DirectSaleShop
    // directSaleShop2.welcome()ss
    ;(directSaleShop as DirectSaleShop).welcome()
  }
}

// 执行测试
;(function () {
  console.log('test start:')
  test()
})()

/*
// 指定编译选项
// % tsc test/test.ts --charset utf-8 --lib es6,dom,es2020 --target es2020
// node run
jarry@jarrys-MacBook-Pro ts % node -v
v16.15.1
jarry@jarrys-MacBook-Pro ts % tsc -v
Version 4.9.4
jarry@jarrys-MacBook-Pro ts % tsc         
jarry@jarrys-MacBook-Pro ts % node test/test.js 
test start:
Bus::run().
Car::run().
Motorcycle::run().
Van::run().
SupermarketShop::greetings
DirectSaleShop::greetings
Shop::Welcome
*/