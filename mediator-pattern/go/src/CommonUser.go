package src

import "fmt"

// 继承基础类的普通用户
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
  c.roomMediator.Send(c.GetName(), message)
}

func (c *CommonUser) SendTo(to string, message string) {
  fmt.Println("CommonUser:SendTo() [user: " + c.GetName() + " message: " + message + "]")
  // 通过中介者来中转消息
  c.roomMediator.SendTo(c.GetName(), to, message)
}

func (c *CommonUser) Recieve(from string, message string) {
  fmt.Println("CommonUser:Recieve() [user: " + c.GetName() + " message: " + message + " from: " + from + "]")
}

func (c *CommonUser) SetName(name string) {
  c.Name = name
}

func (c *CommonUser) GetName() string {
  return c.Name
}
