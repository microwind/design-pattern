export class Manual {
  constructor() {
    this.name = 'PhoneName'
    this.__name__ = 'Manual'
    this.screen = [0, 0]
    this.gpuType = 0
  }

  setName(name) {
    this.name = name
  }

  getName() {
    return this.name
  }

  setScreen(size) {
    this.screen = size
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
