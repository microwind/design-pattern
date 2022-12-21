import { AgencyShop } from './shop/AgencyShop.js'
import { DirectSaleShop } from './shop/DirectSaleShop.js'
import { SupermarketShop } from './shop/SupermarketShop.js'
import { AbstractFactory } from './AbstractFactory.js'

export class ShopFactory extends AbstractFactory {
  getShop(type, options) {
    switch (type) {
      case 'AgencyShop':
        return new AgencyShop(options)
      case 'DirectSaleShop':
        return new DirectSaleShop(options)
      case 'SupermarketShop':
        return new SupermarketShop(options)
      default:
        return undefined
    }
  }
}
