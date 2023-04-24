package main

import (
  "fmt"

  "microwind/src"
)

// main包下的main入口方法
func main() {
  fmt.Println("test start:")
  /**
   * 代理模式就是用一个类来代理另一个类或几个类的功能，以便隔绝外部客户和内部真实类
   * 这样真实类和调用方之间有一个代理屏障，保证了安全
   * 同时真实的类如果初始化过，就不再初始化，提升了性能
   */

  // 声明代理类来执行真实类的能力
  var image = &src.ProxyImage{}
  image.SetFileName("001.jpg")

  // 代理类执行真实类的能力
  image.Display()

  // 再调用一次，真实类不会重复实例化
  image.Display()
}

/**
jarry@jarrys-MacBook-Pro go % go build src/*.go
jarry@jarrys-MacBook-Pro go % go run test/test.go
test start:
ProxyImage::Display() 001.jpg
RealImage::LoadFromDisk()  001.jpg
RealImage::Display() 001.jpg
ProxyImage::Display() 001.jpg
RealImage::Display() 001.jpg
*/
