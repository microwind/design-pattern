import { DrawTool } from './DrawTool.js'

// 定义抽象形状类，桥接图形操作接口DrawTool
export abstract class Shape {
  drawTool: DrawTool
  constructor(drawTool: DrawTool) {
    this.drawTool = drawTool
  }

  abstract draw(x: number, y: number, radius: number): void
}
