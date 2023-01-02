// 命令模式真正的执行类，不直接对外，通过command来调用
export class StockReceiver {
  constructor(name, num) {
    this.name = name
    this.num = num
  }

  buy() {
    console.log(
      this.constructor.name +
        '::buy() [name=' +
        this.name +
        ' num=' +
        this.num +
        ']'
    )
  }

  sell() {
    console.log(
      this.constructor.name +
        '::sell() [name=' +
        this.name +
        ' num=' +
        this.num +
        ']'
    )
  }
}
