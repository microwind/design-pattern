package src

import "fmt"

// 编码模块
type EncodeModule struct {
}

func (en *EncodeModule) Encoding() {
  fmt.Println("EncodeModule::Encoding() 进行编码处理。")
}
