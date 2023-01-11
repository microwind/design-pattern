import { Director } from './Director.js'
import { PhoneBuilder } from './PhoneBuilder.js'
import { ManualBuilder } from './ManualBuilder.js'

export class Application {
  static makeIPhone() {
    const director = new Director()
    // 创建手机
    const phoneBuilder = new PhoneBuilder()
    director.buildIPhone(phoneBuilder)
    const iPhone = phoneBuilder.getProduct()
    console.log('iPhone:' + iPhone.getName() + ' | ', JSON.stringify(iPhone))

    // 创建手册
    const manualBuilder = new ManualBuilder()
    director.buildIPhone(manualBuilder)
    const manual = manualBuilder.getProduct()
    console.log('manual:' + manual.getName() + ' | ', JSON.stringify(manual))
  }

  static makeHuaweiPhone() {
    const director = new Director()

    // 创建手机
    const phoneBuilder = new PhoneBuilder()
    director.buildHuaweiPhone(phoneBuilder)
    const huaweiPhone = phoneBuilder.getProduct()
    console.log(
      'huaweiPhone:' + huaweiPhone.getName() + ' | ',
      JSON.stringify(huaweiPhone)
    )

    // 创建手册
    const manualBuilder = new ManualBuilder()
    director.buildHuaweiPhone(manualBuilder)
    const manual = manualBuilder.getProduct()
    console.log('manual:' + manual.getName() + ' | ', JSON.stringify(manual))
  }
}
