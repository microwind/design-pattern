import { DrawTool } from './DrawTool.js'

// 定义抽象形状类，关联图形操作接口
export abstract class Shape {
  drawTool: DrawTool
  constructor(drawTool: DrawTool) {
    this.drawTool = drawTool
  }

  abstract draw(x: number, y: number, radius: number): void
}
