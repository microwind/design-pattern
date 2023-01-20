import { Shop } from './Shop.js'

// 具体产品类，按抽象产品实现功能
export class AgencyShop extends Shop {
  greetings() {
    console.log('AgencyShop::greetings')
  }
}
