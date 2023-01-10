import { Criteria } from './Criteria.js'
import { Person } from './Person.js'

// 根据标准接口实现的过滤
export class CriteriaMale implements Criteria {
  filter(persons: Person[]): Person[] {
    const malePersons = new Array<Person>()
    for (const person of persons) {
      if (person.getGender().toUpperCase() === 'MALE') {
        malePersons.push(person)
      }
    }
    return malePersons
  }
}
