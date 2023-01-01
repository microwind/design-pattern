import { Facade } from '../src/Facade.js'

export function test() {
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
