import { Criteria } from './Criteria.js'

// 定义Or过滤标准
export class OrCriteria extends Criteria {
  constructor(criteria, otherCriteria) {
    super()
    this.criteria = criteria
    this.otherCriteria = otherCriteria
  }

  filter(persons) {
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
