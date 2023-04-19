import { AbstractUser } from './AbstractUser.js'
import { RoomMediator } from './RoomMediator.js'

// 中介者的具体实现类
export class GeneralRoom implements RoomMediator {
  users: AbstractUser[]
  constructor() {
    this.users = []
  }

  register(user: AbstractUser) {
    // 用户注册登记，追加用户列表
    user.setRoomMediator(this)
    this.users.push(user)
  }

  // 作为中介者通知给某个用户
  sendTo(from: AbstractUser, to: AbstractUser, message: string) {
    console.log(
      `${
        this.constructor.name
      }:sendTo() [from: ${from.getName()} message: ${message} to:${to.getName()}]`
    )
    // 定向发送给指定用户
    to.recieve(from, message)
  }

  // 作为中介者通知给全体用户
  send(from: AbstractUser, message: string) {
    console.log(
      `${
        this.constructor.name
      }:send() [from: ${from.getName()} message: ${message} ]`
    )
    for (const user of this.users) {
      user.recieve(from, message)
    }
  }
}
