package src

import "fmt"

// 网络模块
type NetworkModule struct {
}

func (n *NetworkModule) Request() {
  fmt.Println("NetworkModule::Request() 远程读取。")
}
