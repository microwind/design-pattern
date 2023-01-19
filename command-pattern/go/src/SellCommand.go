package src

import "fmt"

// 出售命令，操作receiver，实现了抽象命令类
type SellCommand struct {
  Name          string `default:"BuyCommand"`
  stockReceiver *StockReceiver
}

func (s *SellCommand) GetName() string {
  return s.Name
}

func (s *SellCommand) SetStockReceiver(stockReceiver *StockReceiver) {
  s.stockReceiver = stockReceiver
}

// 命令类调用执行者来自行真正的动作
func (s *SellCommand) Execute() {
  fmt.Println("SellCommand::Execute() ")
  s.stockReceiver.Sell()
}
