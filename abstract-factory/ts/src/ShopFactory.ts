import { AgencyShop } from './shop/AgencyShop.js'
import { DirectSaleShop } from './shop/DirectSaleShop.js'
import { SupermarketShop } from './shop/SupermarketShop.js'
import { AbstractFactory } from './AbstractFactory.js'
import { Shop } from './shop/Shop.js'
import { Vehicle } from './vehicle/Vehicle.js'

export class ShopFactory extends AbstractFactory {
  getShop(type: String, options: Object): Shop | void {
    switch (type) {
      case 'AgencyShop':
        return new AgencyShop(options)
      case 'DirectSaleShop':
        return new DirectSaleShop(options)
      case 'SupermarketShop':
        return new SupermarketShop(options)
      default:
        return
    }
  }
  getVehicle(type: string): Vehicle | void {
    return
  }
}
