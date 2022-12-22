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
  }

  setScreen(screen) {
    this.manual.setScreen(screen)
  }

  setGPU(no) {
    this.manual.setGpuType(no)
  }

  getProduct() {
    return this.manual
  }
}
