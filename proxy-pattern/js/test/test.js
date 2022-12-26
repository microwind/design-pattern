import { ProxyImage } from '../src/ProxyImage.js'

export function test() {
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
jarry@jarrys-MacBook-Pro js % node test/test.js
test start:
ProxyImage::display() 001.jpg
RealImage::loadFromDisk()  001.jpg
RealImage::display() 001.jpg
ProxyImage::display() 001.jpg
RealImage::display() 001.jpg
*/
