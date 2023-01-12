import { AbstractUser } from './AbstractUser.js'

// 继承基础类的会员用户
export class MemberUser extends AbstractUser {
  constructor(name: string) {
    super(name)
  }
  // 这里覆盖了父类
  override send(message: string) {
    console.log(
      `MemberUser execute send() [user: ${this.getName()} message: ${message} ]`
    )
    // 通过中介者来中转消息
    this.roomMediator.send(this.getName(), message)
  }

  override sendTo(to: string, message: string) {
    console.log(
      `${
        this.constructor.name
      }:sendTo() [user: ${this.getName()} message: ${message} to: ${to}]`
    )
    // 通过中介者来中转消息
    this.roomMediator.sendTo(this.getName(), to, message)
  }

  override recieve(from: string, message: string) {
    console.log(
      `${
        this.constructor.name
      }:recieve() [user: ${this.getName()} message: ${message} from: ${from}]`
    )
  }
}
