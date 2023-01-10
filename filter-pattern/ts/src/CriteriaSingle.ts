import { Criteria } from './Criteria.js'
import { Person } from './Person.js'

// 定义子类覆写父类抽象方法
export class CriteriaSingle implements Criteria {
  filter(persons: Person[]): Person[] {
    const singlePersons: Person[] = []
    for (const person of persons) {
      if (person.getStatus().toUpperCase() === 'SINGLE') {
        singlePersons.push(person)
      }
    }
    return singlePersons
  }
}
