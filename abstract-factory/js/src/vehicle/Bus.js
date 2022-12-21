import { Vehicle } from './Vehicle.js'
export class Bus extends Vehicle {
  constructor(options) {
    super(options)
  }
  run() {
    console.log('Bus::run().')
  }
}