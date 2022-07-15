import { Bus } from './Bus.js'
import { Car } from './Car.js'
import { Motorcycle } from './Motorcycle.js'
import { Van } from './Van.js'
export const VehicleType = {
  BUS: 'bus',
  CAR: 'car',
  MOTORCYCLE: 'motorcycle',
  VAN: 'van',
}
export class VehicleFactory {
  getVehicle(type, options) {
    switch (type) {
      case 'bus':
        return new Bus(options)
      case 'car':
        return new Car(options)
      case 'motorcycle':
        return new Motorcycle(options)
      case 'van':
        return new Van(options)
      default:
        return undefined
    }
  }
}
