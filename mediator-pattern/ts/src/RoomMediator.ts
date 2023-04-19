import { AbstractUser } from './AbstractUser.js'

// 定义中介者接口或抽象类
export interface RoomMediator {
  users: AbstractUser[]
  register(user: AbstractUser): void
  sendTo(from: AbstractUser, to: AbstractUser, message: string): void
  send(from: AbstractUser, message: string): void
}
