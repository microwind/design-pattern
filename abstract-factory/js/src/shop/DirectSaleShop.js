import { Shop } from './Shop.js'

// 具体产品类，按抽象产品实现功能
export class DirectSaleShop extends Shop {
  greetings() {
    console.log('DirectSaleShop::greetings')
  }

  // 属于产品的单独方法
  welcome() {
    console.log('DirectSaleShop::Welcome')
  }
}
