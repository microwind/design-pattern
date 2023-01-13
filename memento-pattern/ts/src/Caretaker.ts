import { Memento } from './Memento.js'

// 负责人(Caretaker)角色，只负责保存备忘录记录，不能修改备忘录对象的内容
export class Caretaker {
  mementoList: Memento[]
  constructor() {
    // 备忘录可以是一个记录，也可以就是一个对象，根据业务场景设置
    this.mementoList = []
  }

  add(memento: Memento) {
    console.log(
      this.constructor.name +
        '::add() [memento = ' +
        memento.constructor.name +
        ']'
    )
    this.mementoList.push(memento)
  }

  get(index: number) {
    return this.mementoList[index]
  }

  getMementoList() {
    return this.mementoList
  }
}
