import { RefinedShape } from './RefinedShape.js'
import { DrawTool } from './DrawTool.js'

// 具体业务类，调用工具来辅助实现功能
export class Circle extends RefinedShape {

  constructor(drawTool: DrawTool) {
    super(drawTool)
  }

  draw(x: number, y: number, radius: number) {
    console.log(`Circle::draw() [x=${x} y=${y} radius=${radius}]`)
    // 通过工具类实际绘制
    this.drawTool.drawStyle()
  }
}
