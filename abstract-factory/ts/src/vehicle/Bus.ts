import { Vehicle } from './Vehicle.js'
export class Bus implements Vehicle {
  run() {
    console.log('Bus::run().')
  }
}