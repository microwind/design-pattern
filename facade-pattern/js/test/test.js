import { Facade } from '../src/Facade.js'

export function test() {
  /**
   * 外观模式就是在外层添加一个访问接口类，客户通过这统一访问接口来访问这些复杂子类。
   * 外观模式与适配器模式比较像，都是提供一个高层访问接口，隔绝外部客户与内部子类。
   * 所不同是外观模式后面的类无需实现相同接口，只是把各种调用整合简化，而适配器需要是同一系列类，为的是解决接口不兼容。
   * 这里声明外观类，外观类的方法里影藏了很多子类的调用。
   */
  const facade = new Facade()
  facade.encoding(123456)
  facade.encrypt(999999)
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
Facade::encoding() [id=123456]
NetworkModule::request() 远程读取。
FileModule::readFile() 读取文件。
EncodeModule::encoding() 进行编码处理。        
FileModule::saveFile() 保存文件。
Facade::encrypt() [id=999999]
FileModule::readFile() 读取文件。
EncodeModule::encoding() 进行编码处理。
*/
