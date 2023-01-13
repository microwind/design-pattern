import { Image } from './Image.js'
import { RealImage } from './RealImage.js'

// 代理类也实现了基础接口
export class ProxyImage implements Image {
  fileName: string
  realImage: RealImage | null
  constructor(fileName: string) {
    this.realImage = null
    this.fileName = fileName
  }

  display() {
    console.log('ProxyImage::display() ' + this.fileName)
    if (this.realImage === null) {
      this.realImage = new RealImage(this.fileName)
    }
    // 代理类调用真实类的方法
    this.realImage.display()
  }
}
