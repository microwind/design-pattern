// 构建可执行环境上下文
export class Context {
  map: Map<string, number>
  constructor() {
    this.map = new Map()
  }

  add(key: string, value: number) {
    this.map.set(key, value)
  }

  get(key: string) {
    return this.map.get(key)
  }
}
