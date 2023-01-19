package src

import "fmt"

// 命令调用类，通过关联命令来实行命令的调用
type CommandInvoker struct {
  Name        string
  commandList []Command
}

func (c *CommandInvoker) GetName() string {
  return c.Name
}

// 储存命令
func (c *CommandInvoker) TakeOrder(command Command) {
  fmt.Println("CommandInvoker::TakeOrder() " + command.GetName())
  c.commandList = append(c.commandList, command)
}

// 统一执行
func (c *CommandInvoker) ExecuteOrders() {
  fmt.Println("CommandInvoker::ExecuteOrders() ")
  for _, command := range c.commandList {
    command.Execute()
  }
  // 命令执行后清除
  c.commandList = c.commandList[:0]
}
