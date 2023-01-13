import { Shape } from './Shape.js'

export class Rectangle extends Shape {
  constructor() {
    super()
    this.type = 'Rectangle'
  }

  override draw() {
    console.log('Rectangle::draw()')
  }
}
