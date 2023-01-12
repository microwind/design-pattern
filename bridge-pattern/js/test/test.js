import { Circle } from '../src/Circle.js'
import { DrawStyleA } from '../src/DrawStyleA.js'
import { DrawStyleB } from '../src/DrawStyleB.js'

export function test() {
  /**
   * 桥接模式是将基础抽象类作为桥接器，用来连接抽象对象和具体动作，将两者充分解耦。
   * 抽象对象和具体动作都有自己的父类或接口，其中抽象对象以基础抽象类为父类，实现约定的方法。
   * 具体对象以抽象对象为父类，实现父类方法，具体动作也有统一的接口，为抽象对象服务。
   * 使用时，通过抽象对象声明具体对象，再传入具体行为，使得具体对象可以使用具体动作。
   */
  // 声明具体对象，并指定具体工具
  const circle = new Circle(new DrawStyleA())
  // 调用对象的方法，里面执行了工具类的方法
  circle.draw(10, 20, 50)
  // 还可以调用父类里的方法
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
Circle::draw() [x=10 y=20 radius=50]
DrawStyleA:drawStyle()
RefinedShape::drawDone(), 执行的drawTool是: DrawStyleA
Circle::draw() [x=11 y=22 radius=33]
DrawStyeB:drawStyle()
RefinedShape::drawDone(), 执行的drawTool是: DrawStyleB
*/
