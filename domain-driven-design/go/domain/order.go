package domain

import "fmt"

// 订单状态枚举
type OrderStatus int

const (
  CREATED OrderStatus = iota
  CANCELED
)

// 订单结构体
type Order struct {
  ID           int
  CustomerName string
  Amount       float64
  Status       OrderStatus
}

// 创建订单
func NewOrder(id int, customerName string, amount float64) *Order {
  if amount < 0 {
    fmt.Println("订单金额不能为负数")
    return nil
  }
  return &Order{
    ID:           id,
    CustomerName: customerName,
    Amount:       amount,
    Status:       CREATED,
  }
}

// 取消订单
func (o *Order) Cancel() {
  if o.Status == CREATED {
    o.Status = CANCELED
    fmt.Printf("订单 ID %d 已取消\n", o.ID)
  } else {
    fmt.Printf("订单 ID %d 已经被取消，无法重复操作\n", o.ID)
  }
}

// 显示订单信息
func (o *Order) Display() {
  fmt.Printf("订单 ID: %d\n客户名称: %s\n订单金额: %.2f\n订单状态: %s\n",
    o.ID, o.CustomerName, o.Amount, o.getStatusString())
}

func (o *Order) getStatusString() string {
  switch o.Status {
  case CREATED:
    return "已创建"
  case CANCELED:
    return "已取消"
  default:
    return "未知状态"
  }
}
