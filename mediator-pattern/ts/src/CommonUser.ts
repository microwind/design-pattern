import { AbstractUser } from './AbstractUser.js'

// 继承基础类的普通用户
export class CommonUser extends AbstractUser {
  constructor(name: string) {
    super(name)
  }

  override send(message: string) {
    console.log(
      `${
        this.constructor.name
      }:send() [user: ${this.getName()} message: ${message} ]`
    )
    // 通过中介者来中转消息
    this.roomMediator.send(this, message)
  }

  override sendTo(to: AbstractUser, message: string) {
    console.log(
      `${
        this.constructor.name
      }:sendTo() [user: ${this.getName()} message: ${message} to: ${to}]`
    )
    // 通过中介者来中转消息
    this.roomMediator.sendTo(this, to, message)
  }

  override recieve(from: AbstractUser, message: string) {
    console.log(
      `${
        this.constructor.name
      }:recieve() [user: ${this.getName()} message: ${message} from: ${from.getName()}]`
    )
  }
}
