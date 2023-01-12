import { Container } from './Container.js'
import { ObjectIterator } from './ObjectIterator.js'

// 对象列表，是一种数据容器，可以创建一个迭代器
export class ObjectList implements Container {
  objects: string[]
  constructor() {
    this.objects = ['Google', 'Apple', 'Amazon']
  }

  createIterator() {
    console.log(
      this.constructor.name + '::createIterator() [获取迭代器 ObjectIterator]'
    )
    // 把当前对象传给迭代器
    return new ObjectIterator(this)
  }

  setObjects(objects: string[]) {
    this.objects = objects
  }

  size() {
    return this.objects.length
  }

  get(index: number) {
    return this.objects[index]
  }
}
