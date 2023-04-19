package src

// 定义中介者接口或抽象类
type RoomMediator interface {
  Register(user AbstractUser)
  SendTo(from AbstractUser, to AbstractUser, message string)
  Send(from AbstractUser, message string)
}
