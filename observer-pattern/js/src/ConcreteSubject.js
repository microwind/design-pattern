import { Subject } from './Subject.js'

// 观察者主题类，也是发布者，重写具体的通知方法。不同主题可以关联不同的观察者。
export class ConcreteSubject extends Subject {
  // 不同的主题类有自己的通知方法，批量通知绑定的观察者
  notify(content) {
    console.log(
      this.constructor.name + '::notify() [content = ' + content + ']'
    )

    this.observers.forEach((v, observer) => {
      observer.update(content)
    })

    // for (const observer of this.observers) {
    //   observer[0].update(content)
    // }
  }
}
