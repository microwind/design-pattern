import { Shape } from './Shape.js'
import { ShapeDecorator } from './ShapeDecorator.js'

// 具体装饰器2
export class ShadowShapeDecorator extends ShapeDecorator {
  constructor(decoratedShape: Shape) {
    super(decoratedShape)
  }

  draw() {
    // this.decoratedShape.draw();
    this.setShadow(this.decoratedShape)
  }

  setShadow(decoratedShape: Shape) {
    console.log(
      'ShadowShapeDecorator::setShadow() ' + decoratedShape.constructor.name
    )
  }
}
