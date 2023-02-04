import { AbstractShape } from './AbstractShape.js'
import { DrawTool } from './DrawTool.js'

// 定义新抽象类继承基础抽象类
export class RefinedShape extends AbstractShape {
  constructor(drawTool: DrawTool) {
    super(drawTool)
  }

  draw(x: number, y: number, radius: number) {
    console.log(`RefinedShape::draw() [x=${x} y=${y} radius=${radius}]`)
    // 通过工具类实际绘制
    this.drawTool.drawStyle()
  }

  // 新抽象类里的方法，可作为补充
  drawDone() {
    console.log(
      'RefinedShape::drawDone(), 执行的drawTool是: ' +
        this.drawTool.constructor.name
    )
  }
}
