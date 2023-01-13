import { ObserverAPI } from './ObserverAPI.js'

// 定义抽象主题类或者接口，供具体主题类继承
export abstract class Subject {
  name: string
  observers: Set<ObserverAPI>
  constructor(name: string) {
    this.name = name
    this.observers = new Set<ObserverAPI>()
  }

  getName() {
    return this.name
  }

  setName(name: string) {
    this.name = name
  }

  register(observer: ObserverAPI) {
    console.log(
      this.constructor.name +
        '::register() [observer = ' +
        observer.constructor.name +
        ']'
    )
    this.observers.add(observer)
  }

  remove(observer: ObserverAPI) {
    this.observers.delete(observer)
  }

  // 通知由具体类来实现逻辑
  abstract notify(name: string): void
}
