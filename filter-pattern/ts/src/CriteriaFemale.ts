import { Criteria } from './Criteria.js'
import { Person } from './Person.js'

// 根据标准接口实现的过滤
export class CriteriaFemale implements Criteria {
  filter(persons: Person[]): Person[] {
    const femalePersons: Person[] = []
    for (const person of persons) {
      if (person.getGender().toUpperCase() === 'FEMALE') {
        femalePersons.push(person)
      }
    }
    return femalePersons
  }
}
