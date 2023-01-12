import { GeneralRoom } from '../src/GeneralRoom.js'
import { CommonUser } from '../src/CommonUser.js'
import { MemberUser } from '../src/MemberUser.js'

export function test() {
  /**
   * 中介者模式用一个中介对象来封装一系列动作，让对象之间利用中介者来交流。
   * 这里聊天室就是一个中介者，用户和用户之间的消息传递，全部依靠聊天室来完成。
   * 先给聊天室注册用户，也给用户绑定上中介者，双方彼此持有关系。
   * 中介者的成员之间的消息传递通过中介者来代理传达。
   */
  // 声明一个聊天室
  const generalRoom = new GeneralRoom()
  // 给聊天室添加点不同的人
  const user1 = new CommonUser('user1')
  generalRoom.register(user1)
  const user2 = new CommonUser('user2')
  generalRoom.register(user2)
  const user3 = new MemberUser('user3')
  generalRoom.register(user3)

  // user1 发送给全体
  user1.send("hi, I'm " + user1.getName() + '.')
  // user2 发送给 user3
  user2.sendTo(user3.getName(), 'haha.')
}

// 执行测试
;(function () {
  console.log('test start:')
  test()
})()
/**
// npm run
jarry@jarrys-MacBook-Pro js % npm run test
// or node execution
jarry@jarrys-MacBook-Pro js % node test/test.js
test start:
CommonUser:send() [user: user1 message: hi, I'm user1. ]
>>GeneralRoom:send() [from: user1 message: hi, I'm user1. ]
CommonUser:recieve() [user: user1 message: hi, I'm user1. from: user1]
CommonUser:recieve() [user: user2 message: hi, I'm user1. from: user1]
MemberUser:recieve() [user: user3 message: hi, I'm user1. from: user1]
CommonUser:sendTo() [user: user2 message: haha. to: user3]
>>GeneralRoom:sendTo() [from: user2 message: haha. to:user3]
MemberUser:recieve() [user: user3 message: haha. from: user2]
*/
