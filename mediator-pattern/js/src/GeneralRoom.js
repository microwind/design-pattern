import { RoomMediator } from './RoomMediator.js'

// 中介者的具体实现类
export class GeneralRoom extends RoomMediator {
  constructor() {
    super()
  }

  // 作为中介者通知给某个用户
  sendTo(from, to, message) {
    console.log(
      `>>${this.constructor.name}:sendTo() [from: ${from} message: ${message} to:${to}]`
    )
    this.users.forEach((user) => {
      // 定向发送
      if (user.getName() === to) {
        user.recieve(from, message)
      }
    })
  }

  // 作为中介者通知给全体用户
  send(from, message) {
    console.log(
      `>>${this.constructor.name}:send() [from: ${from} message: ${message} ]`
    )
    for (const user of this.users) {
      user.recieve(from, message)
    }
  }
}
