import { ProxyImage } from '../src/ProxyImage.js'

export function test() {
  /**
   * 代理模式就是用一个类来代理另一个类或几个类的功能，以便隔绝外部客户和内部真实类
   * 这样真实类和调用方之间有一个代理屏障，保证了安全
   * 同时真实的类如果初始化过，就不再初始化，提升了性能
   */

  // 声明代理类来执行真实类的能力
  const image = new ProxyImage('001.jpg')

  // 代理类执行真实类的能力
  image.display()

  // 再调用一次，不会重复实例化
  image.display()
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
ProxyImage::display() 001.jpg
RealImage::loadFromDisk()  001.jpg
RealImage::display() 001.jpg
ProxyImage::display() 001.jpg
RealImage::display() 001.jpg
*/
