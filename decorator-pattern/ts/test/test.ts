import { Circle } from '../src/Circle.js'
import { Square } from '../src/Square.js'
import { RedShapeDecorator } from '../src/RedShapeDecorator.js'
import { ShadowShapeDecorator } from '../src/ShadowShapeDecorator.js'

export function test() {
  /**
   * 装饰器模式是将一个对象放到一个装饰器对象中，执行装饰器类里的方法时，对象的行为能力得到增强。
   * 先声明具体对象，然后放到装饰器，得到一个带有装饰器的新对象，该对象具备了新的能力。
   */

  // 声明形状
  const circle = new Circle()
  const square = new Square()

  // 增加红色装饰
  const redCircle = new RedShapeDecorator(circle)
  const redSquare = new RedShapeDecorator(square)
  circle.draw()
  redCircle.draw()
  redSquare.draw()

  // 增加影子装饰
  const shadowCircle = new ShadowShapeDecorator(circle)
  const shadowSquare = new ShadowShapeDecorator(square)
  shadowCircle.draw()
  shadowSquare.draw()
}

// 执行测试
;(function () {
  console.log('test start:')
  test()
})()
/**
jarry@jarrys-MacBook-Pro ts % sudo npm install -g ts-node
// direct use `ts-node-esm` or use `tsc` and `node`
jarry@jarrys-MacBook-Pro ts % ts-node-esm test/test.ts
test start:
Circle::draw()
Circle::draw()
RedShapeDecorator::setRedColor() Circle
Square::draw()
RedShapeDecorator::setRedColor() Square
ShadowShapeDecorator::setShadow() Circle
ShadowShapeDecorator::setShadow() Square
*/
