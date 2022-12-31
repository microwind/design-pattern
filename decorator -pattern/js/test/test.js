import { Circle } from '../src/Circle.js'
import { Square } from '../src/Square.js'
import { RedShapeDecorator } from '../src/RedShapeDecorator.js'
import { ShadowShapeDecorator } from '../src/ShadowShapeDecorator.js'

export function test() {
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
// npm run
jarry@jarrys-MacBook-Pro js % npm run test
// or node execution
jarry@jarrys-MacBook-Pro js % node test/test.js
test start:
Circle::draw()
Circle::draw()
RedShapeDecorator::setRedColor() Circle  
Square::draw()
RedShapeDecorator::setRedColor() Square  
ShadowShapeDecorator::setShadow() Circle
ShadowShapeDecorator::setShadow() Square
*/
