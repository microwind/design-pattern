import { StockReceiver } from '../src/StockReceiver.js'
import { BuyCommand } from '../src/BuyCommand.js'
import { SellCommand } from '../src/SellCommand.js'
import { CommandInvoker } from '../src/CommandInvoker.js'

export function test() {
  /*
   * 命令模式是客户端通过一个命令执行者invoker，去执行某个命令command
   * 而命令则调用了业务类receiver的具体动作，从而完成真正的执行
   */

  // 先声明一个被操作对象，也就是接收者
  const stock1 = new StockReceiver('Apple', 200)

  // 再声明具体的命令
  const buyCommand = new BuyCommand(stock1)
  const sellCommand = new SellCommand(stock1)

  // 最后声明调用者，由调用者来执行具体命令
  const invoker = new CommandInvoker()
  invoker.takeOrder(buyCommand)
  invoker.takeOrder(sellCommand)
  invoker.executeOrders()

  // 再执行一只股票
  const stock2 = new StockReceiver('Google', 100)
  const buyCommand2 = new BuyCommand(stock2)
  invoker.takeOrder(buyCommand2)
  invoker.executeOrders()
}

// 执行测试
;(function () {
  console.log('test start:')
  test()
})()
/**
// npm run
jarry@jarrys-MacBook-Pro js % npm run test
// or node execution
jarry@jarrys-MacBook-Pro js % node test/test.js
test start:
CommandInvoker::takeOrder() BuyCommand    
CommandInvoker::takeOrder() SellCommand   
CommandInvoker::executeOrders()
BuyCommand::execute()
StockReceiver::buy() [name=Apple num=200] 
SellCommand::execute()
StockReceiver::sell() [name=Apple num=200]
CommandInvoker::takeOrder() BuyCommand    
CommandInvoker::executeOrders()
BuyCommand::execute()
StockReceiver::buy() [name=Google num=100]
*/
