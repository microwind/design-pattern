import { Shop } from './Shop.js'

export class DirectSaleShop implements Shop {
  constructor(options: Object) {
  }
  greetings(): void {
    console.log('DirectSaleShop::greetings')
  }

  welcome() {
    console.log('Shop::Welcome')
  }
}
