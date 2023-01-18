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
      case VehicleType.BUS:
        return new Bus(options)
      case VehicleType.CAR:
        return new Car(options)
      case VehicleType.MOTORCYCLE:
        return new Motorcycle(options)
      case VehicleType.VAN:
        return new Van(options)
      default:
        return undefined
    }
  }
}
