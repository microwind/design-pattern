// 访问者Visitor抽象接口，定义visit方法，传递元素对象
// JS只是做示范，实际无抽象类
export class Visitor {
  visit(concreteElement) {}
  getName() {
    return this.name
  }
}
