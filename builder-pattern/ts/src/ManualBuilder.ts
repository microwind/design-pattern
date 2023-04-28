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

  setName(name: string): ManualBuilder {
    this.manual.setName(name)
    return this
  }

  setScreen(screen: []): ManualBuilder {
    this.manual.setScreen(screen)
    return this
  }

  setGPU(no: number): ManualBuilder {
    this.manual.setGpuType(no)
    return this
  }

  getProduct() {
    return this.manual
  }
}
