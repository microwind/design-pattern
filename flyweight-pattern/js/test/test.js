import { FlyweightFactory } from '../src/FlyweightFactory.js'
import { UnsharedConcreteFlyweight } from '../src/UnsharedConcreteFlyweight.js'

export function test() {
  /**
   * 享元模式就是将已经声明过的实例或数据保存在内存里，需要使用时则取出来，无需再次实例化和声明。
   * 通过共享多个对象所共有的相同状态，以达到节省开销的目的。
   * 享元模式分为内部状态和外部状态，内部状态基于享元对象共享，外部状态则外部传入或使用非享元类。
   */

  // 假设有钢琴和吉他，钢琴使用者很多需要共享实例，而吉他每次创建新实例

  // 2个一样名称的为共享对象，只创建1个实例，后面的返回缓存实例
  const factory1 = FlyweightFactory.getFactory('piano1')
  const factory2 = FlyweightFactory.getFactory('piano1')
  const factory3 = FlyweightFactory.getFactory('piano2')
  const factory4 = FlyweightFactory.getFactory('piano2')

  factory1.operate('factory1')
  factory2.operate('factory2')
  factory3.operate('factory3')
  factory4.operate('factory4')

  // 查看一共多少个对象
  for (const entry of FlyweightFactory.pool) {
    console.log('享元对象:' + entry[1].getName())
  }

  // 也可直接执行对象里面的operate
  // for (const [key, value] of FlyweightFactory.pool.entries()) {
  //   console.log('保存的对象:' + key)
  //   value.operate(null)
  // }

  // 无需共享的对象，每次都是新实例，每次得到的都是不同实例
  const factory5 = new UnsharedConcreteFlyweight('guitar1')
  const factory6 = new UnsharedConcreteFlyweight('guitar1')
  factory5.operate('factory5')
  factory6.operate('factory6')
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
ConcreteFlyweight::constructor(name) [创建具体享元piano1]
FlyweightFactory::getFactory(name) [成功获取具体享元piano1]
ConcreteFlyweight::constructor(name) [创建具体享元piano2]
FlyweightFactory::getFactory(name) [成功获取具体享元piano2]
ConcreteFlyweight::operate() [piano1, piano, factory1])
ConcreteFlyweight::operate() [piano1, piano, factory2])
ConcreteFlyweight::operate() [piano2, piano, factory3])
ConcreteFlyweight::operate() [piano2, piano, factory4])
享元对象:piano1
享元对象:piano2
UnsharedConcreteFlyweight::constructor(name) [创建非共享对象guitar1]
UnsharedConcreteFlyweight::constructor(name) [创建非共享对象guitar1]
UnsharedConcreteFlyweight::operate() [guitar1, guitar, factory5])
UnsharedConcreteFlyweight::operate() [guitar1, guitar, factory6])
*/
