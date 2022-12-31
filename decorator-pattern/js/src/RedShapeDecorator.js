import { ShapeDecorator } from './ShapeDecorator.js'

// 具体装饰器1
export class RedShapeDecorator extends ShapeDecorator {
  constructor(decoratedShape) {
    super(decoratedShape)
  }

  draw() {
    this.decoratedShape.draw()
    this.setRedColor(this.decoratedShape)
  }

  setRedColor(decoratedShape) {
    console.log(
      'RedShapeDecorator::setRedColor() ' + decoratedShape.constructor.name
    )
  }
}
