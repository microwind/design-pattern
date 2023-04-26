export class EagerSingleton {
  constructor(alias) {
    this.alias = alias
  }

  // 饿汉模式，直接返回已经初始化的实例
  static getInstance(alias) {
    if (this.instance.alias === undefined || this.instance.alias === '') {
      this.instance.alias = alias
    }
    return this.instance
  }

  run() {
    console.log('EagerSingleton::run()', EagerSingleton.instance.alias)
  }
}

// 直接初始化
EagerSingleton.instance = new EagerSingleton('')
