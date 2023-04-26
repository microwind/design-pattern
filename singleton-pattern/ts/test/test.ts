import { LazySingleton } from '../src/LazySingleton.js'
import { EagerSingleton } from '../src/EagerSingleton.js'
import { LazySingletonObject } from '../src/LazySingletonObject.js'

export function test() {
  /**
   * 单例模式就是一个类只创建一个实例，以便节省开销和保证统一
   * 对于多线程语言需要注意线程安全和性能之间取得一个平衡
   */
  const lazySingleton1 = LazySingleton.getInstance('lazySingleton1')
  const lazySingleton2 = LazySingleton.getInstance('lazySingleton2')
  lazySingleton1.run()
  lazySingleton2.run()

  const lazySingletonObject1 = LazySingletonObject.getInstance('lazySingletonObject1')
  const lazySingletonObject2 = LazySingletonObject.getInstance('lazySingletonObject2')
  lazySingletonObject1.run()
  lazySingletonObject2.run()

  const eagerSingleton1 = EagerSingleton.getInstance('eagerSingleton1')
  const eagerSingleton2 = EagerSingleton.getInstance('eagerSingleton2')
  eagerSingleton1.run()
  eagerSingleton2.run()
}

// 执行测试
;(function () {
  console.log('test start:')
  test()
})()
/**
// use ems
jarry@jarrys-MacBook-Pro ts % ts-node-esm test/test.ts
// or tsc and node run
jarry@jarrys-MacBook-Pro ts % tsc
jarry@jarrys-MacBook-Pro ts % node test/test.js
test start:
LazySingleton::run() lazySingleton1
LazySingleton::run() lazySingleton1
LazySingletonObject::() lazySingletonObject1
LazySingletonObject::() lazySingletonObject1
EagerSingleton::run() eagerSingleton1
EagerSingleton::run() eagerSingleton1
*/
