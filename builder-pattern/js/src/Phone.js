export class Phone {
  constructor() {
    this.name = 'PhoneName'
    this.__name__ = 'Phone'
    this.screen = [0, 0]
    this.gpuType = 0
  }

  setName(name) {
    this.name = name
  }

  getName() {
    return this.name
  }

  setScreen(screen) {
    this.screen = screen
  }

  getScreen() {
    return this.screen
  }

  setGpuType(type) {
    this.gpuType = type
  }

  getGpuType() {
    return this.gpuType
  }
}
