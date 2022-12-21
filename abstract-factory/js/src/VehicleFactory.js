import { Bus } from './vehicle/Bus.js'
import { Car } from './vehicle/Car.js'
import { Motorcycle } from './vehicle/Motorcycle.js'
import { Van } from './vehicle/Van.js'
import { AbstractFactory } from './AbstractFactory.js'
export const VehicleType = {
  BUS: 'bus',
  CAR: 'car',
  MOTORCYCLE: 'motorcycle',
  VAN: 'van',
}
export class VehicleFactory extends AbstractFactory {
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
