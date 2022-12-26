import { Image } from './Image.js'

// 真实类实现基础接口
export class RealImage extends Image {
  constructor(fileName) {
    // 在初始化时执行内部逻辑
    super(fileName)
    this.fileName = fileName
    this.loadFromDisk(fileName)
  }

  display() {
    console.log('RealImage::display() ' + this.fileName)
  }

  // 这个方法只是内部使用
  loadFromDisk(fileName) {
    console.log('RealImage::loadFromDisk()  ' + fileName)
  }
}
