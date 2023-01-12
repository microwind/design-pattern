import { VehicleFactory, VehicleType } from '../src/VehicleFactory.js'

export function test() {
  /**
   * 工厂模式由工厂类提供统一的创建对象的方法，省去直接new，而是通过统一方法来创建。
   * 这样的好处就是让对象创建和调用解耦，便于在创建对象时统一干预。
   */
  const vehicleFactory = new VehicleFactory()

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
}

// 执行测试
;(function () {
  console.log('test start:')
  test()
})()
/**
jarry@jarrys-MacBook-Pro js % node --version
v16.15.1
 */
/*
// ts-node-esm run
jarry@jarrys-MacBook-Pro ts % ts-node-esm test/test.ts
test start:
Bus::run().
Car::run().
Motorcycle::run().
Van::run().
*/

/**
// tsc and node run
jarry@jarrys-MacBook-Pro ts % tsc
jarry@jarrys-MacBook-Pro ts % node test/test.js 
test start:
Bus::run().
Car::run().
Motorcycle::run().
Van::run().
*/
