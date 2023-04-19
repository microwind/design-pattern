import {
  AbstractUser
} from './AbstractUser.js'

// 继承基础类的会员用户
export class MemberUser extends AbstractUser {
  constructor(name) {
    super(name)
  }

  // 这里覆盖了父类
  send(message) {
    console.log(
      `MemberUser execute send() [user: ${this.getName()} message: ${message} ]`
    )
    // 通过中介者来中转消息
    this.roomMediator.send(this.getName(), message)
  }
}