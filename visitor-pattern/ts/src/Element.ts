import { Visitor } from './Visitor.js'

// 抽象元素(Element)，定义accept方法，传入抽象访问者
export abstract class Element {
  name: string
  abstract accept(visitor: Visitor): void
  abstract operate(): void
  getName() {
    return this.name
  }
}
