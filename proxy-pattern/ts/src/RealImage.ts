import { Image } from './Image.js'

// 真实类实现基础接口
export class RealImage implements Image {
  fileName: string
  realImage: RealImage | null
  constructor(fileName: string) {
    // 在初始化时执行内部逻辑
    this.fileName = fileName
    this.loadFromDisk(fileName)
  }

  display() {
    console.log('RealImage::display() ' + this.fileName)
  }

  // 这个方法只是内部使用
  loadFromDisk(fileName: string) {
    console.log('RealImage::loadFromDisk()  ' + fileName)
  }
}
