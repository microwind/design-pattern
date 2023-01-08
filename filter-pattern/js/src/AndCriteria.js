import { Criteria } from './Criteria.js'

// 定义And过滤标准
export class AndCriteria extends Criteria {
  constructor(criteria, otherCriteria) {
    super()
    this.criteria = criteria
    this.otherCriteria = otherCriteria
  }

  filter(persons) {
    const firstCriteriaPersons = this.criteria.filter(persons)
    return this.otherCriteria.filter(firstCriteriaPersons)
  }
}
