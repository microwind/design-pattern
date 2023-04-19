package main

import (
  "fmt"

  "microwind/src"
)

// main包下的main入口方法
func main() {
  fmt.Println("test start:")
  /**
   * 中介者模式用一个中介对象来封装一系列动作，让对象之间利用中介者来交流。
   * 这里聊天室就是一个中介者，用户和用户之间的消息传递，全部依靠聊天室来完成。
   * 先给聊天室注册用户，也给用户绑定上中介者，双方彼此持有关系。
   * 中介者的成员之间的消息传递通过中介者来代理传达。
   */
  // 声明一个聊天室
  var generalRoom = new(src.GeneralRoom)
  // 给聊天室添加点不同的人
  var user1 = &src.CommonUser{
    Name: "user1",
  }
  generalRoom.Register(user1)

  var user2 = &src.CommonUser{
    Name: "user2",
  }
  generalRoom.Register(user2)

  var user3 = &src.MemberUser{
    Name: "user3",
  }
  generalRoom.Register(user3)

  // user1 发送给全体
  user1.Send("hi, I'm " + user1.GetName() + ".")
  // user2 发送给 user3
  user2.SendTo(user3, "haha.")
}

/**
jarry@jarrys-MacBook-Pro go % go build src/*.go
jarry@jarrys-MacBook-Pro go % go run test/test.go
test start:
CommonUser:Send() [user: user1 message: hi, I'm user1.]
GeneralRoom::Send() [from: user1 message: hi, I'm user1.]
CommonUser:Recieve() [user: user1 message: hi, I'm user1. from: user1]
CommonUser:Recieve() [user: user2 message: hi, I'm user1. from: user1]
MemberUser:Recieve() [user: user3 message: hi, I'm user1. from: user1]
CommonUser:SendTo() [user: user2 message: haha.]
GeneralRoom::SendTo() [from: user2 message: haha. to: user3]
MemberUser:Recieve() [user: user3 message: haha. from: user2]
*/
