import { Shape } from './Shape.js'

// 具体形状实现了基础形状接口
export class Circle extends Shape {
  draw() {
    console.log('Circle::draw()')
  }
}
