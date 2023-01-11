import { Command } from './Command.js'

// 命令调用类，通过关联命令来实行命令的调用
export class CommandInvoker {
  commandList: Command[]
  constructor() {
    this.commandList = []
  }

  // 储存命令
  takeOrder(command: Command) {
    console.log(
      this.constructor.name + '::takeOrder() ' + command.constructor.name
    )
    this.commandList.push(command)
  }

  // 统一执行
  executeOrders() {
    console.log(this.constructor.name + '::executeOrders() ')
    for (const command of this.commandList) {
      command.execute()
    }
    this.commandList.length = 0
  }
}
