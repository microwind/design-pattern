export class Singleton {
  alias: string
  static singleton: Singleton
  constructor(alias: string) {
    this.alias = alias
  }

  // 懒汉模式，请求实例时判断，如果已经实例化过就直接返回
  // js是单线程语言，无需考虑多线程问题
  static getInstance(alias: string) {
    if (this.singleton === undefined) {
      this.singleton = new Singleton(alias)
    }
    return this.singleton
  }

  run() {
    console.log('Singleton::run()', this.alias)
  }
}
