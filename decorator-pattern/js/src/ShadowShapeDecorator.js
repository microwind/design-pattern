import { ShapeDecorator } from './ShapeDecorator.js'

// 具体装饰器2
export class ShadowShapeDecorator extends ShapeDecorator {
  constructor(decoratedShape) {
    super(decoratedShape)
  }

  draw() {
    // this.decoratedShape.draw();
    this.setShadow(this.decoratedShape)
  }

  setShadow(decoratedShape) {
    console.log(
      'ShadowShapeDecorator::setShadow() ' + decoratedShape.constructor.name
    )
  }
}
