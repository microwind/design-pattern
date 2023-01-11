import { Builder } from './Builder.js'
import { Manual } from './Manual.js'

export class ManualBuilder implements Builder {
  manual: Manual | any
  constructor() {
    // this.reset()
  }

  reset() {
    this.manual = new Manual()
  }

  setName(name: string) {
    this.manual.setName(name)
  }

  setScreen(screen: []) {
    this.manual.setScreen(screen)
  }

  setGPU(no: number) {
    this.manual.setGpuType(no)
  }

  getProduct() {
    return this.manual
  }
}
