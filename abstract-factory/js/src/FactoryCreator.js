import { VehicleFactory } from './VehicleFactory.js'
import { ShopFactory } from './ShopFactory.js'

export class FactoryCreator {
  static getFactory(name, options) {
    switch (name) {
      case 'vehicle':
        return new VehicleFactory(options)
      case 'shop':
        return new ShopFactory(options)
      default:
        return undefined
    }
  }
}
