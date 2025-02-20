package service

import (
  "fmt"
  "go-order-system/domain"
  "go-order-system/repository"
)

// 创建订单
func CreateOrderService(id int, customerName string, amount float64) {
  order := domain.NewOrder(id, customerName, amount)
  if order != nil {
    repository.SaveOrder(order)
    fmt.Printf("订单 ID %d 创建成功\n", id)
  }
}

// 取消订单
func CancelOrderService(id int) {
  order := repository.GetOrderById(id)
  if order != nil {
    order.Cancel()
  } else {
    fmt.Printf("未找到 ID %d\n", id)
  }
}

// 查询订单
func QueryOrderService(id int) {
  order := repository.GetOrderById(id)
  if order != nil {
    order.Display()
  } else {
    fmt.Printf("未找到 ID %d\n", id)
  }
}
