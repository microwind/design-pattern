// 享元角色抽象接口
export interface Flyweight {
  operate(state: string): void
  getName(): string
}
