// 具体商品抽象接口，JS目前还没有抽象类和接口，用父类表示
export class Shop {
  // 用于覆盖
  greetings() {
    console.log('Shop::greetings')
  }
}
