// 定义抽象形状类，关联图形操作接口
// js没有接口和抽象类，用普通类代替亦可
export class Shape {
  constructor(drawTool) {
    this.drawTool = drawTool
  }

  draw(x, y, radius) {}
}