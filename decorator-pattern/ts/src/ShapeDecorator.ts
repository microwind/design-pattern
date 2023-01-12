import { Shape } from './Shape.js'

// 抽象装饰类，是否继承Shape可选
export class ShapeDecorator implements Shape {
  decoratedShape: Shape
  constructor(decoratedShape: Shape) {
    this.decoratedShape = decoratedShape
  }

  draw() {
    this.decoratedShape.draw()
  }
}
