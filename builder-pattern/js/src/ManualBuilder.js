import { Builder } from './Builder.js'
import { Manual } from './Manual.js'

export class ManualBuilder extends Builder {
  constructor() {
    super()
    this.manual = null
  }

  reset() {
    this.manual = new Manual()
  }

  setName(name) {
    this.manual.setName(name)
    return this
  }

  setScreen(screen) {
    this.manual.setScreen(screen)
    return this
  }

  setGPU(no) {
    this.manual.setGpuType(no)
    return this
  }

  getProduct() {
    return this.manual
  }
}
