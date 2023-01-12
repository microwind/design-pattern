import { FlyweightFactory } from '../src/FlyweightFactory.js'
import { UnsharedConcreteFlyweight } from '../src/UnsharedConcreteFlyweight.js'

export function test() {
  /**
   * 享元模式就是将已经声明过的实例或数据保存在内存里，需要使用时则取出来，无需再次实例化和声明。
   * 通过共享多个对象所共有的相同状态，以达到节省开销的目的。
   */

  // 假设有钢琴和吉他，钢琴使用者很多需要共享实例，而吉他每次创建新实例

  // 2个一样名称的共享对象
  const factory1 = FlyweightFactory.getFactory('piano1')
  // piano1已经声明过了，同名则共享前面的实例
  const factory2 = FlyweightFactory.getFactory('piano1')
  const factory3 = FlyweightFactory.getFactory('piano2')

  factory1.operate('factory1')
  factory2.operate('factory2')
  factory3.operate('factory3')

  // 查看一共多少个对象
  for (const entry of FlyweightFactory.pool) {
    console.log('保存的对象:' + entry[1].getName())
  }
  // for (const [key, value] of FlyweightFactory.pool.entries()) {
  // console.log('保存的对象:' + key)
  // value.operate(null)
  // }

  // 无需共享的，名字一样也是多个对象
  const factory4 = new UnsharedConcreteFlyweight('guitar1')
  const factory5 = new UnsharedConcreteFlyweight('guitar1')
  factory4.operate('factory4')
  factory5.operate('factory5')
}

// 执行测试
;(function () {
  console.log('test start:')
  test()
})()

/**
jarry@jarrys-MacBook-Pro ts % ts-node-esm test/test.ts
// 或tsc再node执行
jarry@jarrys-MacBook-Pro ts % tsc
jarry@jarrys-MacBook-Pro ts % node test/test.js
test start:
ConcreteFlyweight::operate() [piano1, piano, factory1])
ConcreteFlyweight::operate() [piano1, piano, factory2])
ConcreteFlyweight::operate() [piano2, piano, factory3])
保存的对象:piano1
保存的对象:piano2
UnsharedConcreteFlyweight::operate() [guitar1, guitar, factory4])
UnsharedConcreteFlyweight::operate() [guitar1, guitar, factory5])
*/
