import { Shop } from './Shop.js'

// 具体产品类，实现抽象产品类
export class DirectSaleShop implements Shop {
  constructor(options: Object) {
  }
  greetings(): void {
    console.log('DirectSaleShop::greetings')
  }

  // 属于产品的单独方法
  welcome() {
    console.log('DirectSaleShop::welcome()')
  }
}
