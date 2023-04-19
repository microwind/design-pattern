// 定义中介者接口或抽象类
export class RoomMediator {
  constructor() {
    this.users = []
  }

  register(user) {
    // 用户注册登记，追加用户列表
    user.setRoomMediator(this)
    this.users.push(user)
  }
  sendTo(from, to, message) {}
  send(from, message) {}
}