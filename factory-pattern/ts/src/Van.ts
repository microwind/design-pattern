import { Vehicle } from './Vehicle.js'
export class Van implements Vehicle {
  constructor(options: object) {}
  run() {
    console.log('Van::run().')
  }
}
