package src

// 定义中介者接口或抽象类
type RoomMediator interface {
  Register(user AbstractUser)
  SendTo(from string, to string, message string)
  Send(from string, message string)
}
