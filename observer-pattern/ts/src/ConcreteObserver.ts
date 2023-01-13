import { ObserverAPI } from './ObserverAPI.js'
import { Subject } from './Subject.js'

// 具体的观察者实现类，也可以看成订阅者，关联对应的主题类。
// 不同的观察者也可以对应多个主题
export class ConcreteObserver extends ObserverAPI {
  // 给观察者绑定主题，同时把观察者添加到主题列表
  subject: Subject
  constructor(subject: Subject, name: string) {
    super(name)
    this.subject = subject
    subject.register(this)
  }

  // 观察者发出更新通知，不用单独告诉订阅者，由订阅者自行监听
  update(content: string) {
    console.log(
      `${this.constructor.name}::update() [subject.name = ${this.subject.name} content = ${content}]`
    )
  }
}
