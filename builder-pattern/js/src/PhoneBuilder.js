import { Builder } from './Builder.js'
import { Phone } from './Phone.js'

export class PhoneBuilder extends Builder {
  constructor() {
    super()
    this.phone = null
  }

  reset() {
    this.phone = new Phone()
  }

  setName(name) {
    this.phone.setName(name)
  }

  setScreen(screen) {
    this.phone.setScreen(screen)
  }

  setGPU(no) {
    this.phone.setGpuType(no)
  }

  getProduct() {
    return this.phone
  }
}
