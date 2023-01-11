import { Application } from '../src/Application.js'
import { Director } from '../src/Director.js'
import { PhoneBuilder } from '../src/PhoneBuilder.js'
import { ManualBuilder } from '../src/ManualBuilder.js'

export function test() {
  Application.makeIPhone()

  Application.makeHuaweiPhone()

  // *********************** 分割线 ******************************************/

  // 声明指挥者
  const director = new Director()
  // 创建手机
  const phoneBuilder = new PhoneBuilder()
  director.buildMiPhone(phoneBuilder)
  const miPhone = phoneBuilder.getProduct()
  console.log('miPhone:' + miPhone.getName() + ' | ', JSON.stringify(miPhone))
  // 创建手册
  const manualBuilder = new ManualBuilder()
  director.buildMiPhone(manualBuilder)
  const manual = manualBuilder.getProduct()
  console.log('manual:' + manual.getName() + ' | ', JSON.stringify(manual))
}

// 执行测试
;(function () {
  console.log('test start:')
  test()
})()
/**
jarry@jarrys-MacBook-Pro ts % tsc
jarry@jarrys-MacBook-Pro ts % node test/test.js
test start:
iPhone:iPhone |  {"name":"iPhone","__name__":"Phone","screen":[120,500],"gpuType":100}
manual:iPhone |  {"name":"iPhone","__name__":"Manual","screen":[120,500],"gpuType":100}
huaweiPhone:HuaweiPhone |  {"name":"HuaweiPhone","__name__":"Phone","screen":[140,600],"gpuType":102}
manual:HuaweiPhone |  {"name":"HuaweiPhone","__name__":"Manual","screen":[140,600],"gpuType":102}
miPhone:MiPhone |  {"name":"MiPhone","__name__":"Phone","screen":[130,550],"gpuType":103}
manual:MiPhone |  {"name":"MiPhone","__name__":"Manual","screen":[130,550],"gpuType":103}
*/
