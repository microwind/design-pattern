import { Shape } from './Shape.js'
import { DrawTool } from './DrawTool.js'

// 定义新抽象类继承基础抽象类
export class RefinedShape extends Shape {
  constructor(drawTool: DrawTool) {
    super(drawTool)
  }

  // 覆盖父类的方法，会被真正的类再覆盖
  draw(x: number, y: number, radius: number) {
    console.log(`RefinedShape::draw() [x=${x} y=${y} radius=${radius}]`)
  }

  // 新抽象类里的方法，可作为补充
  drawDone() {
    console.log(
      'RefinedShape::drawDone(), 执行的drawTool是: ' +
        this.drawTool.constructor.name
    )
  }
}
