import { Vehicle } from './Vehicle.js'

// 具体产品类，按抽象产品实现功能
export class Car extends Vehicle {
  constructor(options) {
    super(options)
  }

  run() {
    console.log('Car::run().')
  }
}
