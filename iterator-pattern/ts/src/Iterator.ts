// 迭代器抽象接口，提供next和hasNext方法
export interface Iterator {
  hasNext(): void
  next(): void
}
