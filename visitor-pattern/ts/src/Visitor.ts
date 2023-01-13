import { ConcreteElementA } from './ConcreteElementA'
import { ConcreteElementB } from './ConcreteElementB'

// 访问者Visitor抽象接口，定义visit方法，传递元素对象
export interface Visitor {
  name: string
  visit(concreteElementA: ConcreteElementA): void
  visit(concreteElementB: ConcreteElementB): void
  getName(): string
}
