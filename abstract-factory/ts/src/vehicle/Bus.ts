import { Vehicle } from './Vehicle.js'
// 具体产品类，实现抽象产品类
export class Bus implements Vehicle {
  run() {
    console.log('Bus::run().')
  }
}