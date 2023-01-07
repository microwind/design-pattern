import { ConcreteSubject } from '../src/ConcreteSubject.js'
import { ConcreteObserver } from '../src/ConcreteObserver.js'
import { ConcreteObserver2 } from '../src/ConcreteObserver2.js'

export function test() {
  /**
   * 观察者模式应用非常广泛，主要是观察者提前绑定到发布者
   * 当发布者发布消息时，批量广播通知，而无需逐一通知
   * 观察者监听到消息后自己决定采取哪一种行为
   */

  // 定义一个主题，也就是发布者
  const concreteSubject = new ConcreteSubject('subject1')
  // 再声明观察者，通过构造器注册到主题上
  const observer1 = new ConcreteObserver(concreteSubject)
  // 也可以单独给主题注册一个新的观察者
  const observer2 = new ConcreteObserver2()
  concreteSubject.register(observer2)
  // 可以移除观察者对象
  // concreteSubject.remove(observer1)

  // 主题开始发布新通知，各观察者自动更新
  concreteSubject.notify('hello, this is broadcast.')
}

// 执行测试
;(function () {
  console.log('test start:')
  test()
})()
/**
// npm run
jarry@jarrys-MacBook-Pro js % npm run test
// or node execution
jarry@jarrys-MacBook-Pro js % node test/test.js
test start:
ConcreteSubject::register() [observer = ConcreteObserver]
ConcreteSubject::register() [observer = ConcreteObserver2]
ConcreteSubject::notify() [content = hello, this is broadcast.]
ConcreteObserver::update() [subject.name = subject1 content = hello, this is broadcast.]
ConcreteObserver2::update() [content = hello, this is broadcast.]
*/
