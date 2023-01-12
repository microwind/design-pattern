import { ConcreteFlyweight } from './ConcreteFlyweight.js'
import { Flyweight } from './Flyweight.js'

// 享元工厂，储存一个对象共享池，已经生成过的对象直接取出
export class FlyweightFactory {

  // 静态属性
  static pool: Map<string, Flyweight> = new Map()

  // 这里的name可以认为是内部状态，在构造时确定，具有唯一性。
  static getFactory(name: string) {
    const pool = FlyweightFactory.pool
    let flyweight = pool.get(name)
    if (!flyweight) {
      // 如果对象不存在则创建新的对象放入到池子里，如果已经存在则复用前面的对象
      flyweight = new ConcreteFlyweight(name)
      pool.set(name, flyweight)
    }
    return flyweight
  }
}
