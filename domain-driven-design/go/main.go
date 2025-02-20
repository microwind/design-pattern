package main

import (
  "fmt"
  "go-order-system/repository"
  "go-order-system/service"
)

func main() {
  for {
    fmt.Println("\n订单管理系统")
    fmt.Println("1. 创建订单")
    fmt.Println("2. 取消订单")
    fmt.Println("3. 查询订单")
    fmt.Println("4. 查看订单历史")
    fmt.Println("5. 退出")
    fmt.Print("请选择操作: ")

    var choice int
    fmt.Scan(&choice)

    switch choice {
    case 1:
      var id int
      var customerName string
      var amount float64
      fmt.Print("请输入订单 ID: ")
      fmt.Scan(&id)
      fmt.Print("请输入客户名称: ")
      fmt.Scan(&customerName)
      fmt.Print("请输入订单金额: ")
      fmt.Scan(&amount)
      service.CreateOrderService(id, customerName, amount)

    case 2:
      var id int
      fmt.Print("请输入要取消的订单 ID: ")
      fmt.Scan(&id)
      service.CancelOrderService(id)

    case 3:
      var id int
      fmt.Print("请输入要查询的订单 ID: ")
      fmt.Scan(&id)
      service.QueryOrderService(id)

    case 4:
      repository.ViewOrderHistory()

    case 5:
      fmt.Println("退出系统，清理资源...")
      repository.ClearOrders()
      return

    default:
      fmt.Println("无效选择，请重新输入。")
    }
  }
}

/*
jarry@MacBook-Pro go % go version
go version go1.23.5 darwin/arm64
jarry@MacBook-Pro go % go run main.go

订单管理系统
1. 创建订单
2. 取消订单
3. 查询订单
4. 查看订单历史
5. 退出
请选择操作: 3
请输入要查询的订单 ID: 23
未找到 ID 23
*/
