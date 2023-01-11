import { AbstractHandler } from '../src/AbstractHandler.js'
import { AuthHandler } from '../src/AuthHandler.js'
import { UserHandler } from '../src/UserHandler.js'
import { RequestHandler } from '../src/RequestHandler.js'

export function test() {
  // 责任链模式核心是打造一个调用处理链，每个处理链都实现抽象类的next方法，从而可以任意组织各种检查链。

  // 可以任意组织职责链，先后顺序根据需要来
  const handler1 = AbstractHandler.link(
    new RequestHandler(),
    new UserHandler(),
    new AuthHandler()
  )

  console.log('handler1.check(1001)开始')
  handler1.check(1001)
  console.log('handler1.check(1002)开始')
  handler1.check(1002)

  // 可以任意组织职责链，先后顺序根据需要来
  const handler2 = AbstractHandler.link(
    new AuthHandler(),
    new RequestHandler(),
    new UserHandler()
  )

  console.log('handler2.check(1001)开始')
  handler2.check(1001)
  console.log('handler2.check(1002)开始')
  handler2.check(1002)
}

// 执行测试
;(function () {
  console.log('test start:')
  test()
})()
/**
jarry@jarrys-MacBook-Pro ts % tsc
jarry@jarrys-MacBook-Pro ts % node test/test.js
test start:
handler1.check(1001)开始
RequestHandler::check() [uid = 1001]
UserHandler::check() [uid = 1001]
AuthHandler::check() [uid = 1001]
handler1.check(1002)开始
RequestHandler::check() [uid = 1002]
UserHandler::check() [uid = 1002]
handler2.check(1001)开始
AuthHandler::check() [uid = 1001]
RequestHandler::check() [uid = 1001]
UserHandler::check() [uid = 1001]
handler2.check(1002)开始
AuthHandler::check() [uid = 1002]
*/
