import { Builder } from './Builder.js'

// 指挥调度类，负责利用建造者建造产品，隔离需求
export class Director {
  // 建造phone1
  buildIPhone(builder: Builder) {
    builder.reset()
    const screen = [120, 500]
    builder.setName('iPhone')
    builder.setScreen(screen)
    builder.setGPU(100)
  }

  // 建造phone2
  buildHuaweiPhone(builder: Builder) {
    builder.reset()
    const screen = [140, 600]
    // 也可链式调用
    builder.setName('HuaweiPhone').setScreen(screen).setGPU(102)
  }

  // 建造phone3
  buildMiPhone(builder: Builder) {
    builder.reset()
    const screen = [130, 550]
    builder.setName('MiPhone')
    builder.setScreen(screen)
    builder.setGPU(103)
  }
}
