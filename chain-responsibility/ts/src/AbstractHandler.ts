// 抽象处理类，所有处理变成链式，可以互动干涉，动态组合
export abstract class AbstractHandler {
  next: AbstractHandler
  constructor() {

  }

  // 创建调用链，传入多个handler，按顺序形成链，返回第一个handler
  static link(first: AbstractHandler, ...chain: AbstractHandler[]) {
    let head = first
    for (const handler of chain) {
      head.next = handler
      head = handler
    }

    return first
  }

  // 子类需要实现的检查方法
  abstract check(uid: number): void 

  // 继续下一个检查
  checkNext(uid: number) {
    if (!this.next) {
      return true
    }
    return this.next.check(uid)
  }
}
