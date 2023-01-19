package src

import "fmt"

// 购买命令，操作receiver，实现了抽象命令类
type BuyCommand struct {
  Name          string `default:"BuyCommand"`
  stockReceiver *StockReceiver
}

func (c *BuyCommand) GetName() string {
  return c.Name
}

func (c *BuyCommand) SetStockReceiver(stockReceiver *StockReceiver) {
  c.stockReceiver = stockReceiver
}

// 命令类调用执行者来自行真正的动作
func (c *BuyCommand) Execute() {
  fmt.Println("BuyCommand::Execute() ")
  c.stockReceiver.Buy()
}
