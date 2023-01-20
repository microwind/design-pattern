import { VehicleFactory } from './VehicleFactory.js'
import { ShopFactory } from './ShopFactory.js'

// 工厂创建类，用于创建基于抽象工厂规范的具体工厂
export class FactoryCreator {
  static getFactory(name) {
    switch (name) {
      case 'vehicle':
        return new VehicleFactory()
      case 'shop':
        return new ShopFactory()
      default:
        return undefined
    }
  }
}
