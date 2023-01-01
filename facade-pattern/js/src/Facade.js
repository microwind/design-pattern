import { AbstractFacade } from './AbstractFacade.js'
import { FileModule } from './FileModule.js'
import { NetworkModule } from './NetworkModule.js'
import { EncodeModule } from './EncodeModule.js'

// 外观模式实现类，是外部调用与内部子系统的衔接层
export class Facade extends AbstractFacade {
  constructor() {
    super()
    this.fileModule = new FileModule()
    this.networkModule = new NetworkModule()
    this.encodeModule = new EncodeModule()
  }

  encoding(id) {
    console.log(this.constructor.name + '::encoding() [id=' + id + ']')
    this.networkModule.request()
    this.fileModule.readFile()
    this.encodeModule.encoding()
    this.fileModule.saveFile()
  }

  encrypt(id) {
    console.log(this.constructor.name + '::encrypt() [id=' + id + ']')
    this.fileModule.readFile()
    this.encodeModule.encoding()
  }

  getFileModule() {
    return this.fileModule
  }

  getNetworkModule() {
    return this.networkModule
  }

  getEncodeModule() {
    return this.encodeModule
  }
}
