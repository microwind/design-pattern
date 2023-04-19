package src

// 基础用户类，供具体继承
type AbstractUser interface {
  SetRoomMediator(roomMediator RoomMediator)
  Send(message string)
  SendTo(to AbstractUser, message string)
  Recieve(from AbstractUser, message string)
  GetName() string
}
