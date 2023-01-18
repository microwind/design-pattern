// 享元角色抽象接口
export interface Flyweight {
  name: string;
  operate(state: string): void
  getName(): string
}
