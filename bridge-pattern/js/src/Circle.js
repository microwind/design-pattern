import { RefinedShape } from './RefinedShape.js'

// 具体业务类，调用工具来辅助实现功能
export class Circle extends RefinedShape {
  constructor(drawTool) {
    super(drawTool)
  }

  draw(x, y, radius) {
    console.log(`Circle::draw() [x=${x} y=${y} radius=${radius}]`)
    // 通过工具类实际绘制
    this.drawTool.drawStyle()
  }
}
