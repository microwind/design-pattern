import { Shape } from "./Shape.js"

export class Square extends Shape {
  constructor() {
    super()
    this.type = 'Square'
  }

  override draw() {
    console.log('Square::draw()')
  }
}
