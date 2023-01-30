package main

import (
  "fmt"

  "microwind/src"
)

// main包下的main入口方法
func main() {
  fmt.Println("test start:")
  /**
   * 责任链模式核心是打造一个调用处理链，每个处理链都实现抽象类的next方法，从而可以任意组织各种检查行为。
   * 通过改变链内的成员或者调动它们的顺序，允许动态地新增或者删除职责，从而实现按需组织。
   */

  // 可以任意组织职责链，先后顺序根据需要来
  var AbstractHandler = &src.AbstractHandler{}
  var handler1 = AbstractHandler.Link(
    &src.RequestHandler{
      Name: "RequestHandler",
    },
    &src.UserHandler{
      Name: "UserHandler",
    },
    &src.AuthHandler{
      Name: "AuthHandler",
    },
  )

  fmt.Println("handler1.check(1001)开始")
  handler1.Check(1001)
  fmt.Println("handler1.check(1002)开始")
  handler1.Check(1002)

  // 可以任意组织职责链，先后顺序根据需要来
  var handler2 = AbstractHandler.Link(
    &src.AuthHandler{
      Name: "AuthHandler",
    },
    &src.RequestHandler{
      Name: "RequestHandler",
    },
    &src.UserHandler{
      Name: "UserHandler",
    },
  )

  fmt.Println("handler2.check(1001)开始")
  handler2.Check(1001)
  fmt.Println("handler2.check(1002)开始")
  handler2.Check(1002)
}

/**
jarry@jarrys-MacBook-Pro go % go build src/*.go
jarry@jarrys-MacBook-Pro go % go run test/test.go
test start:
handler1.check(1001)开始
RequestHandler::Check() [uid = 1001]
UserHandler::Check() [uid = 1001]
AuthHandler::Check() [uid = 1001]
handler1.check(1002)开始
RequestHandler::Check() [uid = 1002]
UserHandler::Check() [uid = 1002]
handler2.check(1001)开始
AuthHandler::Check() [uid = 1001]
RequestHandler::Check() [uid = 1001]
UserHandler::Check() [uid = 1001]
handler2.check(1002)开始
AuthHandler::Check() [uid = 1002]
*/
