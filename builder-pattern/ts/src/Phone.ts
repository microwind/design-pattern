export class Phone {
  name: string
  __name__: string
  screen: number[]
  gpuType: number
  constructor() {
    this.name = 'PhoneName'
    this.__name__ = 'Phone'
    this.screen = [0, 0]
    this.gpuType = 0
  }

  setName(name: string) {
    this.name = name
  }

  getName() {
    return this.name
  }

  setScreen(size: number[]) {
    this.screen = size
  }

  getScreen() {
    return this.screen
  }

  setGpuType(type: number) {
    this.gpuType = type
  }

  getGpuType() {
    return this.gpuType
  }
}
