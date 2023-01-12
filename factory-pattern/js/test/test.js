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
// node run
jarry@jarrys-MacBook-Pro js % node -v
v16.15.1
jarry@jarrys-MacBook-Pro js % node test/test.js
test start:
Bus::run().
Car::run().
Motorcycle::run().
Van::run().
*/

/*
// npm run
jarry@jarrys-MacBook-Pro js % npm run test

> esm-project@1.0.0 test
> node test/test.js

test start:
Bus::run().
Car::run().
Motorcycle::run().
Van::run().
*/

/**
// n run
jarry@jarrys-MacBook-Pro js % n run 14.17.0 test/test.js
test start:
Bus::run().
Car::run().
Motorcycle::run().
Van::run().
*/

/*
// node 10.24.1 isn't support es module
// Node 13.2.0 can support ES Modules
jarry@jarrys-MacBook-Pro js % n run 10.24.1 test/test.js
/Users/jarry/github/design-pattern/factory-pattern/js/test/test.js:1
import { VehicleFactory, VehicleType } from '../src/VehicleFactroy.js'
       ^

SyntaxError: Unexpected token {
    at Module._compile (internal/modules/cjs/loader.js:723:23)
    at Object.Module._extensions..js (internal/modules/cjs/loader.js:789:10)
    at Module.load (internal/modules/cjs/loader.js:653:32)
    at tryModuleLoad (internal/modules/cjs/loader.js:593:12)
    at Function.Module._load (internal/modules/cjs/loader.js:585:3)
    at Function.Module.runMain (internal/modules/cjs/loader.js:831:12)
    at startup (internal/bootstrap/node.js:283:19)
    at bootstrapNodeJSCore (internal/bootstrap/node.js:623:3)
jarry@jarrys-MacBook-Pro js %
*/
