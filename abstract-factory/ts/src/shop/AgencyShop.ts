import { Shop } from './Shop.js'

// 具体产品类，实现抽象产品类
export class AgencyShop implements Shop {
  constructor(options: Object) {
  }
  greetings(): void {
    console.log('AgencyShop::greetings')
  }
}
