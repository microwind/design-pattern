export class Singleton {
  constructor(alias) {
    this.alias = alias
  }

  static getInstance(alias) {
    if (this.singleton === undefined) {
      this.singleton = new Singleton(alias)
    }
    return this.singleton
  }

  run() {
    console.log('Singleton::run()', this.alias)
  }
}
