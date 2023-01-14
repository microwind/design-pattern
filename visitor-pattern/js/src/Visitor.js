// 访问者Visitor抽象接口，定义visit方法，传递元素对象
// JS只是做示范，实际无抽象类，继承父类便于区分来自同一类型
export class Visitor {
  // abstract method
  visit(Element) {
    // pass
  }

  getName() {
    return this.name
  }
}