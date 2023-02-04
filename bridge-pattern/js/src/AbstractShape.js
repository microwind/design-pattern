// 定义抽象形状类，桥接图形操作接口DrawTool
// js没有接口和抽象类，用普通类代替亦可
export class AbstractShape {
  constructor(drawTool) {
    this.drawTool = drawTool
  }

  draw(x, y, radius) {}
}