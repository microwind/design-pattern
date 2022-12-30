import { GeneralRoom } from '../src/GeneralRoom.js'
import { CommonUser } from '../src/CommonUser.js'
import { MemberUser } from '../src/MemberUser.js'

export function test() {
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
