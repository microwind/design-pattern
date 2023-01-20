import { Vehicle } from './Vehicle.js'

// 具体产品类，按抽象产品实现功能
export class Bus extends Vehicle {
  constructor(options) {
    super(options)
  }
  run() {
    console.log('Bus::run().')
  }
}