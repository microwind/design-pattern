import { Criteria } from './Criteria.js'

// 根据标准接口实现的过滤
export class CriteriaMale extends Criteria {
  filter(persons) {
    const malePersons = []
    for (const person of persons) {
      if (person.getGender().toUpperCase() === 'MALE') {
        malePersons.push(person)
      }
    }
    return malePersons
  }
}
