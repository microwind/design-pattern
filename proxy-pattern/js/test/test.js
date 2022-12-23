import { Singleton } from '../src/Singleton.js'
import { SingleObject } from '../src/SingleObject.js'

export function test() {
  const singleton1 = Singleton.getInstance('singleton1')
  singleton1.run()
  const singleton2 = Singleton.getInstance('singleton2')
  singleton2.run()

  const singleObject1 = SingleObject.getInstance('single1')
  singleObject1.run()
  const singleObject2 = SingleObject.getInstance('single2')
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
