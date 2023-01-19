package src

// 命令抽象接口
type Command interface {
  GetName() string
  SetStockReceiver(stockReceiver *StockReceiver)
  Execute()
}
