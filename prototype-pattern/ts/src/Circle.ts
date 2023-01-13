import { Shape } from './Shape.js'

export class Circle extends Shape {
  constructor() {
    super()
    this.type = 'Circle'
  }

  override draw() {
    console.log('Circle::draw()')
  }
}
