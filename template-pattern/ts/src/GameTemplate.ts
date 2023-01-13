// 定义抽象模板类
export abstract class GameTemplate {
  // 抽象方法待子类来实现
  abstract init(): void

  abstract start(): void

  abstract end(): void

  // 可复用的算法流程
  play() {
    console.log(this.constructor.name + '::play()')

    // 初始化游戏
    this.init()

    // 开始游戏
    this.start()

    // 结束游戏
    this.end()
  }
}
