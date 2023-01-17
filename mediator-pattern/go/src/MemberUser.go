package src

import "fmt"

// 继承基础类的普通用户
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
  c.roomMediator.Send(c.GetName(), message)
}

func (c *MemberUser) SendTo(to string, message string) {
  fmt.Println("MemberUser:SendTo() [user: " + c.GetName() + " message: " + message + "]")
  // 通过中介者来中转消息
  c.roomMediator.SendTo(c.GetName(), to, message)
}

func (c *MemberUser) Recieve(from string, message string) {
  fmt.Println("MemberUser:Recieve() [user: " + c.GetName() + " message: " + message + " from: " + from + "]")
}

func (c *MemberUser) SetName(name string) {
  c.Name = name
}

func (c *MemberUser) GetName() string {
  return c.Name
}
