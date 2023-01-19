package src

import (
  "fmt"
  "strconv"
)

// 命令模式真正的执行类，不直接对外，通过command来调用
type StockReceiver struct {
  Name string
  Num  int
}

func (s *StockReceiver) Buy() {
  fmt.Println("StockReceiver::Buy() [Name=" +
    s.Name + " Num=" + strconv.Itoa(s.Num) + "]")
}

func (s *StockReceiver) Sell() {
  fmt.Println("StockReceiver::Sell() [Name=" +
    s.Name + " Num=" + strconv.Itoa(s.Num) + "]")
}
