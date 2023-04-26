export class LazySingleton {
  static instance
  constructor(alias) {
    this.alias = alias
  }

  // 懒汉模式，延迟实例化，请求实例时判断，如果已经实例化过就直接返回
  // js是单线程语言，无需考虑多线程问题
  static getInstance(alias) {
    if (this.instance === undefined) {
      this.instance = new LazySingleton(alias)
    }
    return this.instance
  }

  run() {
    console.log('LazySingleton::run()', this.alias)
  }
}