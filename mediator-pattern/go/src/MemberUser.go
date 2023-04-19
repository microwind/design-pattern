package src

import "fmt"

// 实现基础类的普通用户2，聚合了中介者
type MemberUser struct {
  // Name首字母大写以便跨模块访问
  Name         string
  roomMediator RoomMediator
}

func (c *MemberUser) SetRoomMediator(roomMediator RoomMediator) {
  c.roomMediator = roomMediator
}

func (c *MemberUser) Send(message string) {
  fmt.Println("MemberUser:Send() [user: " + c.GetName() + " message: " + message + "]")
  // 通过中介者来中转消息
  c.roomMediator.Send(c, message)
}

func (c *MemberUser) SendTo(to AbstractUser, message string) {
  fmt.Println("MemberUser:SendTo() [user: " + c.GetName() + " message: " + message + "]")
  // 通过中介者来中转消息
  c.roomMediator.SendTo(c, to, message)
}

func (c *MemberUser) Recieve(from AbstractUser, message string) {
  fmt.Println("MemberUser:Recieve() [user: " + c.GetName() + " message: " + message + " from: " + from.GetName() + "]")
}

func (c *MemberUser) SetName(name string) {
  c.Name = name
}

func (c *MemberUser) GetName() string {
  return c.Name
}
