import { Originator } from '../src/Originator.js'
import { Caretaker } from '../src/Caretaker.js'

export function test() {
  /*
   * 备忘录模式是在不暴露对象实现细节的情况下保存和恢复对象之前的状态。
   * 先声明发起人Originator，再声明负责人Caretaker，发起人生成备忘录Memento
   * 通过负责人则保存备忘录历史记录，读取备忘录由负责人来完成。
   */
  const originator = new Originator()
  const careTaker = new Caretaker()
  // 发起人产生一个状态
  originator.setState('state1')
  // 覆盖了状态，那么前面的状态未保存
  originator.setState('state2')
  // 发起人生成备忘录，一般添加时直接保存即可
  const memento = originator.saveMemento()
  // 负责人保添加备忘录历史记录
  careTaker.add(memento)

  // 直接生成备忘录并添加到负责人的备忘录列表
  originator.setState('state3')
  careTaker.add(originator.saveMemento())
  originator.setState('state4')
  careTaker.add(originator.saveMemento())

  console.log('发起人当前的状态: ' + originator.getState())

  // 发起人通过负责人那里取出状态
  originator.restoreMemento(careTaker.get(0))
  console.log('第一个保存的状态: ' + originator.getState())
  originator.restoreMemento(careTaker.get(1))
  console.log('第二个保存的状态: ' + originator.getState())

  // 遍历全部备忘录
  for (let i = 0; i < careTaker.getMementoList().length; i++) {
    // 外部一般不直接访问备忘录里面的状态，而是逐个恢复备忘录，再取出状态来
    originator.restoreMemento(careTaker.get(i))
    console.log('state: ' + i + ')' + originator.getState())
  }
}

// 执行测试
;(function () {
  console.log('test start:')
  test()
})()

/**
 // use ems
 jarry@jarrys-MacBook-Pro ts % ts-node-esm test/test.ts
 // or tsc and node run
jarry@jarrys-MacBook-Pro ts % tsc
jarry@jarrys-MacBook-Pro ts % node test/test.js
test start:
Originator::saveMemento() [state = state2]
Memento::Memento() [state = state2]
Caretaker::add() [memento = Memento]
Originator::saveMemento() [state = state3]
Memento::Memento() [state = state3]
Caretaker::add() [memento = Memento]
Originator::saveMemento() [state = state4]
Memento::Memento() [state = state4]
Caretaker::add() [memento = Memento]
发起人当前的状态: state4
第一个保存的状态: state2
第二个保存的状态: state3
state: 0)state2
state: 1)state3
state: 2)state4
*/
