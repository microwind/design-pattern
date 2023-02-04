import { AbstractShape } from './AbstractShape.js'

// 具体桥接类，继承抽象桥接类，扩充了自己的函数
// 通过依赖的工具来辅助具体功能
export class RefinedShape extends AbstractShape {
  constructor(drawTool) {
    super(drawTool)
  }

  draw(x, y, radius) {
    console.log(`RefinedShape::draw() [x=${x} y=${y} radius=${radius}]`)
    // 通过工具类实际绘制
    this.drawTool.drawStyle()
  }

  // 新抽象类里的方法，可作为补充
  drawDone() {
    console.log('RefinedShape::drawDone(), 执行的drawTool是: ' + this.drawTool.constructor.name)
  }
}
