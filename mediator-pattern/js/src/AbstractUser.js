// 基础用户类，供具体继承
export class AbstractUser {
  constructor(name) {
    this.name = name
  }

  setRoomMediator(roomMediator) {
    this.roomMediator = roomMediator
  }

  send(message) {
    console.log(
      `${this.constructor.name}:send() [user: ${this.getName()} message: ${message} ]`
    )
    // 通过中介者来中转消息
    this.roomMediator.send(this.getName(), message)
  }

  sendTo(to, message) {
    console.log(
      `${this.constructor.name}:sendTo() [user: ${this.getName()} message: ${message} to: ${to}]`
    )
    // 通过中介者来中转消息
    this.roomMediator.sendTo(this.getName(), to, message)
  }

  recieve(from, message) {
    console.log(
      `${this.constructor.name}:recieve() [user: ${this.getName()} message: ${message} from: ${from}]`
    )
  }

  getName() {
    return this.name
  }
}
