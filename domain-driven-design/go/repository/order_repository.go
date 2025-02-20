package repository

import (
  "fmt"
  "go-order-system/domain"
)

const maxOrders = 100

var orderStorage []*domain.Order

// 保存订单
func SaveOrder(order *domain.Order) {
  if len(orderStorage) >= maxOrders {
    fmt.Println("存储容量已满，无法保存订单")
    return
  }
  orderStorage = append(orderStorage, order)
}

// 获取订单
func GetOrderById(id int) *domain.Order {
  for _, order := range orderStorage {
    if order.ID == id {
      return order
    }
  }
  return nil
}

// 查看订单历史
func ViewOrderHistory() {
  if len(orderStorage) == 0 {
    fmt.Println("暂无订单历史记录。")
    return
  }
  for _, order := range orderStorage {
    order.Display()
    fmt.Println()
  }
}

// 清理订单
func ClearOrders() {
  orderStorage = nil
  fmt.Println("所有订单已清理")
}
