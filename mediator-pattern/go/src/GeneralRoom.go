package src

import (
  "fmt"
)

// 中介者的具体实现类
type GeneralRoom struct {
  users []AbstractUser
}

func (g *GeneralRoom) Register(user AbstractUser) {
  // 用户注册登记，追加用户列表
  user.SetRoomMediator(g)
  g.users = append(g.users, user)
}

// 作为中介者通知给某个用户
func (g *GeneralRoom) SendTo(from string, to string, message string) {
  fmt.Println(">>GeneralRoom::SendTo() [from: " + from + " message: " + message + " to: " + to + "]")
  for _, user := range g.users {
    // 定向发送给某个用户
    if user.GetName() == to {
      user.Recieve(from, message)
    }
  }
}

// 作为中介者通知给全体用户
func (g *GeneralRoom) Send(from string, message string) {
  fmt.Println(">>GeneralRoom::Send() [from: " + from + " message: " + message + "] ")
  for _, user := range g.users {
    user.Recieve(from, message)
  }
}
