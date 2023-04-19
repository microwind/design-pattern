package src

import (
  "fmt"
)

// 中介者的具体实现类，聚合了全体用户，提供中转消息服务
type GeneralRoom struct {
  users []AbstractUser
}

func (g *GeneralRoom) Register(user AbstractUser) {
  // 用户注册登记，追加用户列表
  user.SetRoomMediator(g)
  g.users = append(g.users, user)
}

// 作为中介者通知给某个用户
func (g *GeneralRoom) SendTo(from AbstractUser, to AbstractUser, message string) {
  fmt.Println("GeneralRoom::SendTo() [from: " + from.GetName() + " message: " + message + " to: " + to.GetName() + "]")
  // 定向发送给某个用户，名称唯一
  to.Recieve(from, message)
}

// 作为中介者通知给全体用户
func (g *GeneralRoom) Send(from AbstractUser, message string) {
  fmt.Println("GeneralRoom::Send() [from: " + from.GetName() + " message: " + message + "] ")
  for _, user := range g.users {
    user.Recieve(from, message)
  }
}
