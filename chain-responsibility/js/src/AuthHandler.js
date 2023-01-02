import { AbstractHandler } from './AbstractHandler.js'

// 权限检查类
export class AuthHandler extends AbstractHandler {
  // 如果检查不通过则返回失败，否则继续下一个检查
  check(uid) {
    console.log(this.constructor.name + '::check() [uid = ' + uid + ']')
    if (uid % 2 == 0) {
      return false
    }
    return this.checkNext(uid)
  }
}
