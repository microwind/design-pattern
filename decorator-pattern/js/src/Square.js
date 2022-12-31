import { Shape } from './Shape.js'

// 具体形状实现了基础形状接口
export class Square extends Shape {
  draw() {
    console.log('Square::draw()')
  }
}
