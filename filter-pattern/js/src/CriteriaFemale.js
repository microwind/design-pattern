import { Criteria } from './Criteria.js'

// 根据标准接口实现的过滤
export class CriteriaFemale extends Criteria {
  filter(persons) {
    const femalePersons = []
    for (const person of persons) {
      if (person.getGender().toUpperCase() === 'FEMALE') {
        femalePersons.push(person)
      }
    }
    return femalePersons
  }
}
