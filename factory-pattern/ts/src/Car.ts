import { Vehicle } from './Vehicle.js'
export class Car implements Vehicle {
  constructor(options: object) {}
  run() {
    console.log('Car::run().')
  }
}
