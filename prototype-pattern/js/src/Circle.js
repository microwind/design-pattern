import { Shape } from './Shape.js'

export class Circle extends Shape {
  constructor() {
    super()
    this.type = 'Circle'
  }

  draw() {
    console.log('Circle::draw()')
  }
}
