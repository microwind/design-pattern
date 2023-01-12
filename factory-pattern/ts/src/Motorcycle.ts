import { Vehicle } from './Vehicle.js'
export class Motorcycle implements Vehicle {
  constructor(options: object) {}
  run() {
    console.log('Motorcycle::run().')
  }
}
