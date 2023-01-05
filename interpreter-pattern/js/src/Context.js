// 构建可执行环境上下文
export class Context {
  constructor(key, value) {
    this.map = new Map()
    this.add(key, value)
  }

  add(key, value) {
    this.map.set(key, value)
  }

  get(key) {
    return this.map.get(key)
  }
}
