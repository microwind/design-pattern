import { Builder } from './Builder.js'
import { Phone } from './Phone.js'

export class PhoneBuilder implements Builder {
  phone: Phone | any
  constructor() {
    // this.reset()
  }

  reset() {
    this.phone = new Phone()
  }

  setName(name: string) {
    this.phone.setName(name)
  }

  setScreen(screen: []) {
    this.phone.setScreen(screen)
  }

  setGPU(no: number) {
    this.phone.setGpuType(no)
  }

  getProduct() {
    return this.phone
  }
}
