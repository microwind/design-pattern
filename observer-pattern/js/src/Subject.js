// 定义抽象主题类或者接口，供具体主题类继承
export class Subject {
  constructor(name) {
    this.name = name
    this.observers = new Set()
  }

  getName() {
    return this.name
  }

  setName(name) {
    this.name = name
  }

  register(observer) {
    console.log(
      this.constructor.name +
        '::register() [observer = ' +
        observer.constructor.name +
        ']'
    )
    this.observers.add(observer)
  }

  remove(observer) {
    this.observers.delete(observer)
  }

  // 通知由具体类来实现逻辑
  notify(content) {
    // todo
  }
}
