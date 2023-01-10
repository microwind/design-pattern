import { Shop } from './Shop.js'

export class SupermarketShop implements Shop {
  constructor(options: Object) {
  }
  greetings(): void {
    console.log('SupermarketShop::greetings')
  }
}
