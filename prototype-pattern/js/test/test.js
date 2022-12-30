import { Application } from '../src/Application.js'
import { Square } from '../src/Square.js'

export function test() {
  const application = new Application()
  application.addToShapes()
  const shapeClone = application.getShapeClone(1)
  // 更改clone
  shapeClone.setColor('gray')
  console.log('shapeClone : ' + shapeClone.toString())
  // 直接更改
  application.getShape(3).setColor('yellow')
  application.printShapes()

  // /*********************** 分割线 ******************************************/
  application.shapes.push(new Square())
  for (const shape of application.shapes) {
    shape.draw()
    console.log(shape)
  }
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
shapeClone : {width = 10, height = 20, type = Circle, color = gray }
shape 0 : {width = 10, height = 20, type = Circle, color = red }
shape 1 : {width = 10, height = 20, type = Circle, color = pink }
shape 2 : {width = 99, height = 69, type = Rectangle, color = green }
shape 3 : {width = 99, height = 69, type = Rectangle, color = yellow }
Circle::draw()
Circle { width: 10, height: 20, color: 'red', type: 'Circle' }
Circle::draw()
Circle { width: 10, height: 20, color: 'pink', type: 'Circle' }
Rectangle::draw()
Rectangle { width: 99, height: 69, color: 'green', type: 'Rectangle' }
Rectangle::draw()
Rectangle { width: 99, height: 69, color: 'yellow', type: 'Rectangle' }
Square::draw()
Square { width: 0, height: 0, color: '', type: 'Square' }
*/
