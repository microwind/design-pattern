import { Criteria } from './Criteria.js'
import { Person } from './Person.js'

// 定义And过滤标准
export class AndCriteria implements Criteria {
  criteria: Criteria
  otherCriteria: Criteria
  constructor(criteria: Criteria, otherCriteria: Criteria) {
    this.criteria = criteria
    this.otherCriteria = otherCriteria
  }

  filter(persons: Person[]): Person[] {
    const firstCriteriaPersons = this.criteria.filter(persons)
    return this.otherCriteria.filter(firstCriteriaPersons)
  }
}
