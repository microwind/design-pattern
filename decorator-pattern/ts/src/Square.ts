import { Shape } from './Shape.js'

// 具体形状实现了基础形状接口
export class Square implements Shape {
  draw() {
    console.log('Square::draw()')
  }
}
