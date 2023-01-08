import { Criteria } from './Criteria.js'

// 定义子类覆写父类抽象方法
export class CriteriaSingle extends Criteria {
  filter(persons) {
    const singlePersons = []
    for (const person of persons) {
      if (person.getStatus().toUpperCase() === 'SINGLE') {
        singlePersons.push(person)
      }
    }
    return singlePersons
  }
}
