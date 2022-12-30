import { Shape } from './Shape.js'

// 定义新抽象类继承基础抽象类
export class RefinedShape extends Shape {
  constructor(drawTool) {
    super(drawTool)
  }

  // 新抽象类里的方法，可作为补充
  drawDone() {
    console.log('RefinedShape::drawDone(), 执行的drawTool是: ' + this.drawTool.constructor.name)
  }
}
