import { Command } from './Command.js'
import { StockReceiver } from './StockReceiver.js'

// 购买命令，操作receiver，实现了抽象命令类
export class BuyCommand implements Command {
  stockReceiver: StockReceiver
  constructor(stockReceiver: StockReceiver) {
    this.stockReceiver = stockReceiver
  }

  // 命令类调用执行者来自行真正的动作
  execute() {
    console.log(this.constructor.name + '::execute() ')
    this.stockReceiver.buy()
  }
}
