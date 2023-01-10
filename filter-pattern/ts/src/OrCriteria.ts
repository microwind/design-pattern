import { Criteria } from './Criteria.js'
import { Person } from './Person.js'

// 定义Or过滤标准
export class OrCriteria implements Criteria {
  criteria: Criteria
  otherCriteria: Criteria
  constructor(criteria: Criteria, otherCriteria: Criteria) {
    this.criteria = criteria
    this.otherCriteria = otherCriteria
  }

  filter(persons: Person[]): Person[] {
    const firstCriteriaItems = this.criteria.filter(persons)
    const otherCriteriaItems = this.otherCriteria.filter(persons)
    for (const person of otherCriteriaItems) {
      if (!firstCriteriaItems.includes(person)) {
        firstCriteriaItems.push(person)
      }
    }
    return firstCriteriaItems
  }
}
