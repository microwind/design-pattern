import {
  RoomMediator
} from './RoomMediator.js'

// 中介者的具体实现类
export class GeneralRoom extends RoomMediator {
  constructor() {
    super()
  }

  // 作为中介者通知给某个用户
  sendTo(from, to, message) {
    console.log(
      `${this.constructor.name}:sendTo() [from: ${from.getName()} message: ${message} to:${to.getName()}]`
    )
    // 定向发送
    to.recieve(from, message)
  }

  // 作为中介者通知给全体用户
  send(from, message) {
    console.log(
      `${this.constructor.name}:send() [from: ${from.getName()} message: ${message} ]`
    )
    for (const user of this.users) {
      user.recieve(from, message)
    }
  }
}