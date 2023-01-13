export class Singleton {
  alias: string
  static singleton: Singleton
  constructor(alias: string) {
    this.alias = alias
  }

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
