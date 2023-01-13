import { Circle } from './Circle.js'
import { Rectangle } from './Rectangle.js'
import { Shape } from './Shape.js'

export class Application {
  shapes: Shape[]
  constructor() {
    this.shapes = []
  }

  addToShapes() {
    const circle = new Circle()
    circle.setWidth(10)
    circle.setHeight(20)
    circle.setColor('red')
    this.shapes.push(circle)

    // 添加clone
    const anotherCircle = circle.clone()
    anotherCircle.setColor('pink')
    this.shapes.push(anotherCircle)
    // 变量 `anotherCircle（另一个圆）`与 `circle（圆）`对象的内容完全一样。

    const rectangle = new Rectangle()
    rectangle.setWidth(99)
    rectangle.setHeight(69)
    rectangle.setColor('green')
    this.shapes.push(rectangle)
    // 添加clone
    this.shapes.push(rectangle.clone())
  }

  getShape(index: number) {
    return this.shapes[index]
  }

  getShapeClone(index: number) {
    const shape = this.shapes[index]
    if (shape) {
      return shape.clone()
    }
  }

  printShapes() {
    for (let i = 0; i < this.shapes.length; i++) {
      const shape = this.shapes[i]
      console.log('shape ' + i + ' : ' + shape)
    }
  }
}
