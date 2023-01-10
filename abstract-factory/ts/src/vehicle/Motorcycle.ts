import { Vehicle } from './Vehicle.js'
export class Motorcycle implements Vehicle {
  run() {
    console.log('Motorcycle::run().')
  }
}