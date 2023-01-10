import { Shop } from './Shop.js'

export class AgencyShop implements Shop {
  constructor(options: Object) {
  }
  greetings(): void {
    console.log('AgencyShop::greetings')
  }
}
