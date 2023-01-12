import { Iterator } from './Iterator.js'
import { ObjectList } from './ObjectList.js'

// 对象迭代器，实现了抽象迭代器的方法，聚合了对象列表
export class ObjectIterator implements Iterator {
  objectList: ObjectList
  index: number
  constructor(objectList: ObjectList) {
    this.index = 0
    this.objectList = objectList
  }

  hasNext() {
    if (this.index < this.objectList.size()) {
      return true
    }
    return false
  }

  next() {
    if (this.hasNext()) {
      // 返回数据对象提供的get方法，每访问一次则增加下标
      return this.objectList.get(this.index++)
    }
    return null
  }
}
