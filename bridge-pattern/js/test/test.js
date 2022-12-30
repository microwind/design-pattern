import { Circle } from '../src/Circle.js'
import { DrawStyleA } from '../src/DrawStyleA.js'
import { DrawStyleB } from '../src/DrawStyleB.js'

export function test() {
  // 声明具体对象，并指定具体工具
  const circle = new Circle(new DrawStyleA())
  // 调用对象的方法，里面执行了工具类的方法
  circle.draw(10, 20, 50)
  //还可以调用父类里的方法
  circle.drawDone()

  // /*********************** 分割线 ******************************************/

  // 声明具体对象，并指定另外的工具
  const circle2 = new Circle(new DrawStyleB())
  // 调用对象的方法，里面执行了工具类的方法
  circle2.draw(11, 22, 33)
  // 还可以调用父类里的方法
  circle2.drawDone()
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
test start:
Circle::draw() [x=10 y=20 radius=50]
DrawStyleA:drawStyle()
RefinedShape::drawDone(), 执行的drawTool是: DrawStyleA
Circle::draw() [x=11 y=22 radius=33]
DrawStyeB:drawStyle()
RefinedShape::drawDone(), 执行的drawTool是: DrawStyleB
*/
