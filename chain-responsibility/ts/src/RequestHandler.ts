import { AbstractHandler } from './AbstractHandler.js'

// 请求是否安全合法检查
export class RequestHandler extends AbstractHandler {
  // 如果检查不通过则返回失败，否则继续下一个检查
  check(uid: number) {
    console.log(this.constructor.name + '::check() [uid = ' + uid + ']')
    if (uid % 5 === 0) {
      return false
    }
    return this.checkNext(uid)
  }
}
