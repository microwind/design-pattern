import { Shape } from "./Shape.js"

export class Square extends Shape {
  constructor() {
    super()
    this.type = 'Square'
  }

  draw() {
    console.log('Square::draw()')
  }
}
