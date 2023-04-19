package src

import "fmt"

// 实现基础类的普通用户1，聚合了中介者
type CommonUser struct {
  Name         string
  roomMediator RoomMediator
}

func (c *CommonUser) SetRoomMediator(roomMediator RoomMediator) {
  c.roomMediator = roomMediator
}

func (c *CommonUser) Send(message string) {
  fmt.Println("CommonUser:Send() [user: " + c.GetName() + " message: " + message + "]")
  // 通过中介者来中转消息
  c.roomMediator.Send(c, message)
}

func (c *CommonUser) SendTo(to AbstractUser, message string) {
  fmt.Println("CommonUser:SendTo() [user: " + c.GetName() + " message: " + message + "]")
  // 通过中介者来中转消息
  c.roomMediator.SendTo(c, to, message)
}

func (c *CommonUser) Recieve(from AbstractUser, message string) {
  fmt.Println("CommonUser:Recieve() [user: " + c.GetName() + " message: " + message + " from: " + from.GetName() + "]")
}

func (c *CommonUser) SetName(name string) {
  c.Name = name
}

func (c *CommonUser) GetName() string {
  return c.Name
}
