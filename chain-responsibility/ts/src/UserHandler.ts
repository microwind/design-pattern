import { AbstractHandler } from './AbstractHandler.js'

// 用户基本信息检查类
export class UserHandler extends AbstractHandler {
  // 如果检查不通过则返回失败，否则继续下一个检查
  check(uid: number) {
    console.log(this.constructor.name + '::check() [uid = ' + uid + ']')
    if (uid % 3 == 0) {
      return false
    }
    return this.checkNext(uid)
  }
}
