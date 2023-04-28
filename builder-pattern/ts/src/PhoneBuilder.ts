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

  setName(name: string): PhoneBuilder {
    this.phone.setName(name)
    return this
  }

  setScreen(screen: []): PhoneBuilder {
    this.phone.setScreen(screen)
    return this
  }

  setGPU(no: number): PhoneBuilder {
    this.phone.setGpuType(no)
    return this
  }

  getProduct() {
    return this.phone
  }
}
