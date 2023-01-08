// 抽象元素(Element)，定义accept方法，传入抽象访问者
export class Element {
  accept(visitor) {}
  getName() {
    return this.name
  }
}
