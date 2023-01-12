import { Vehicle } from './Vehicle.js'
export class Bus implements Vehicle {
  constructor(options: object) {}
  run() {
    console.log('Bus::run().')
  }
}
