import { Singleton } from '../src/Singleton.js'
import { SingleObject } from '../src/SingleObject.js'

export function test() {
  /**
   * 单例模式就是一个类只创建一个实例，以便节省开销和保证统一
   * 对于多线程语言需要注意线程安全和性能之间取得一个平衡
   */
  const singleton1 = Singleton.getInstance('singleton1')
  const singleton2 = Singleton.getInstance('singleton2')
  singleton1.run()
  singleton2.run()

  const singleObject1 = SingleObject.getInstance('single1')
  const singleObject2 = SingleObject.getInstance('single2')
  singleObject1.run()
  singleObject2.run()
}

// 执行测试
;(function () {
  console.log('test start:')
  test()
})()
/**
jarry@jarrys-MacBook-Pro js % node test/test.js
test start:
Singleton::run() singleton1
Singleton::run() singleton1
SingleObject::() single1
SingleObject::() single1
*/
