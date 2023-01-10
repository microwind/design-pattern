import { VehicleFactory } from './VehicleFactory.js'
import { ShopFactory } from './ShopFactory.js'
import { AbstractFactory } from './AbstractFactory.js'

export type FactoryType = AbstractFactory | VehicleFactory | ShopFactory | void

export class FactoryCreator {
  static getFactory(name: string): FactoryType {
    switch (name) {
      case 'vehicle':
        return new VehicleFactory()
      case 'shop':
        return new ShopFactory()
      default:
        return
    }
  }
}
