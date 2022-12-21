import { Vehicle } from './Vehicle.js'
export class Motorcycle extends Vehicle {
  constructor(options) {
    super(options)
  }
  run() {
    console.log('Motorcycle::run().')
  }
}