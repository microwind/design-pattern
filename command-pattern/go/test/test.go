package main

import (
  "fmt"

  "microwind/src"
)

// main包下的main入口方法
func main() {
  fmt.Println("test start:")
  /*
   * 命令模式是客户端通过一个命令执行者invoker，去执行某个命令command
   * 而命令则调用了业务类receiver的具体动作，从而完成真正的执行
   * 这种方式将命令和执行者进行了有效解耦。
   */

  // 先声明一个被操作对象，也就是接收者
  var stock1 = &src.StockReceiver{
    Name: "Apple",
    Num:  200,
  }

  // 再声明具体的命令
  var buyCommand = &src.BuyCommand{
    Name: "buyCommand",
  }
  buyCommand.SetStockReceiver(stock1)
  var sellCommand = &src.SellCommand{
    Name: "sellCommand",
  }
  sellCommand.SetStockReceiver(stock1)

  // 最后声明调用者，由调用者来执行具体命令
  var invoker = &src.CommandInvoker{
    Name: "invoker",
  }
  invoker.TakeOrder(buyCommand)
  invoker.TakeOrder(sellCommand)
  invoker.ExecuteOrders()

  // 再执行一只股票
  var stock2 = &src.StockReceiver{
    Name: "Google",
    Num:  100,
  }
  var buyCommand2 = &src.BuyCommand{
    Name: "buyCommand2",
  }
  buyCommand2.SetStockReceiver(stock2)
  invoker.TakeOrder(buyCommand2)
  invoker.ExecuteOrders()
}

/**
jarry@jarrys-MacBook-Pro go % go build src/*.go
jarry@jarrys-MacBook-Pro go % go run test/test.go
test start:
CommandInvoker::TakeOrder() buyCommand
CommandInvoker::TakeOrder() sellCommand
CommandInvoker::ExecuteOrders()
BuyCommand::Execute()
StockReceiver::Buy() [Name=Apple Num=200]
SellCommand::Execute()
StockReceiver::Sell() [Name=Apple Num=200]
CommandInvoker::TakeOrder() buyCommand2
CommandInvoker::ExecuteOrders()
BuyCommand::Execute()
StockReceiver::Buy() [Name=Google Num=100]
*/
