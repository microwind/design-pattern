import { Command } from './Command.js'

// 出售命令，操作receiver，实现了抽象命令类
export class SellCommand extends Command {
  constructor(stockReceiver) {
    super()
    this.stockReceiver = stockReceiver
  }

  // 命令类调用执行者来自行真正的动作
  execute() {
    console.log(this.constructor.name + '::execute() ')
    this.stockReceiver.sell()
  }
}
