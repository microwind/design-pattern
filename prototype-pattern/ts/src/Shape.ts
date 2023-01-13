// 基础抽象类
export abstract class Shape {
  width: number
  height: number
  color: string
  type: string
  constructor() {
    this.width = 0
    this.height = 0
    this.color = ''
    this.type = ''
  }

  // 抽象方法，子类覆盖
  abstract draw(): void

  setWidth(width: number) {
    this.width = width
  }

  getWidth() {
    return this.width
  }

  getHeight() {
    return this.height
  }

  setHeight(height: number) {
    this.height = height
  }

  setColor(color: string) {
    this.color = color
  }

  getColor() {
    return this.color
  }

  // es6自带原型继承与属性复制
  clone() {
    const copy = Object.create(this)
    return Object.assign(copy, this)
  }

  // 模拟实现原型继承与属性复制
  clonePolyfill() {
    // 共享原型

    // function F() {}
    // F.prototype = this
    // const obj = new (F as any)()

    class F {}
    F.prototype = this
    const obj: any = new F()

    // 复制属性
    for (let prop in this) {
      if (this.hasOwnProperty(prop)) {
        obj[prop] = this[prop]
      }
    }
    return obj
  }

  toString() {
    // return JSON.stringify(this)
    return `{width = ${this.width}, height = ${this.height}, type = ${this.type}, color = ${this.color} }`
  }
}
