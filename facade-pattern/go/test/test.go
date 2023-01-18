package main

import (
  "fmt"

  "../src"
)

// main包下的main入口方法
func main() {
  fmt.Println("test start:")
  /**
   * 外观模式就是在外层添加一个访问接口类，客户通过这统一访问接口来访问这些复杂子类。
   * 外观模式与适配器模式比较像，都是提供一个高层访问接口，隔绝外部客户与内部子类。
   * 所不同是外观模式后面的类无需实现相同接口，只是把各种调用整合简化，而适配器需要是同一系列类，为的是解决接口不兼容。
   * 这里声明外观类，外观类的方法里影藏了很多子类的调用。
   */
  var facade = new(src.Facade)
  facade.Encoding(123456)
  facade.Encrypt(999999)
}

/**
jarry@jarrys-MacBook-Pro go % go build src/*.go
jarry@jarrys-MacBook-Pro go % go run test/test.go
test start:
Facade::Encoding() [id=123456]
NetworkModule::Request() 远程读取。
FileModule::ReadFile() 读取文件。
EncodeModule::Encoding() 进行编码处理。
FileModule::SaveFile() 保存文件。
Facade::Encrypt() [id=999999]
FileModule::ReadFile() 读取文件。
EncodeModule::Encoding() 进行编码处理。
*/
