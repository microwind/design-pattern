// 观察者抽象父类，定义一些公共方法
export class ObserverAPI {
  constructor(name) {
    this.name = name || this.constructor.name
  }

  // 观察者发出更新通知，观察者自行监听
  update(content) {
    console.log(`${this.constructor.name}::update() [content = ${content}]`)
  }

  setName(name) {
    this.name = name
  }
}
