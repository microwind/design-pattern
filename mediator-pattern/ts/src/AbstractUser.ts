import { RoomMediator } from './RoomMediator.js'

// 基础用户类，供具体继承
export abstract class AbstractUser {
  roomMediator: RoomMediator
  name: string
  constructor(name: string) {
    this.name = name
  }

  setRoomMediator(roomMediator: RoomMediator) {
    this.roomMediator = roomMediator
  }

  abstract send(message: string): void

  abstract sendTo(to: string, message: string): void

  abstract recieve(from: string, message: string): void

  getName() {
    return this.name
  }
}
