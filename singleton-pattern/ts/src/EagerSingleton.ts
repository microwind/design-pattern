export class EagerSingleton {
  alias: string
  static instance: EagerSingleton
  constructor(alias: string) {
    this.alias = alias
  }

  // 饿汉模式，直接返回已经初始化的实例
  static getInstance(alias: string) {
    if (this.instance.alias === undefined || this.instance.alias === '') {
      this.instance.alias = alias
    }
    return this.instance
  }

  run() {
    console.log('EagerSingleton::run()', this.alias)
  }
}

// 直接初始化
EagerSingleton.instance = new EagerSingleton('')

