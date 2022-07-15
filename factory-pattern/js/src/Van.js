import { Vehicle } from './Vehicle.js'
export class Van extends Vehicle {
  constructor(options) {
    super(options)
  }
  run() {
    console.log('Van::run().')
  }
}