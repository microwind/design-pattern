import { AbstractUser } from './AbstractUser.js'

// 定义中介者接口或抽象类
export interface RoomMediator {
  users: AbstractUser[]
  register(user: AbstractUser): void
  sendTo(from: string, to: string, message: string): void
  send(from: string, message: string): void
}
