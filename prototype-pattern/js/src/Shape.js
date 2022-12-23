export class Shape {
  constructor() {
    this.width = 0
    this.height = 0
    this.color = ''
    this.type = null
  }

  draw() {
    console.log('Shape::draw()')
  }

  setWidth(width) {
    this.width = width
  }

  getWidth() {
    return this.width
  }

  getHeight() {
    return this.height
  }

  setHeight(height) {
    this.height = height
  }

  setColor(color) {
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
    function F() {}
    // 共享原型
    F.prototype = this
    let obj = new F()

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
