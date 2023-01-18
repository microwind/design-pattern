package src

// 定义Or过滤标准
type OrCriteria struct {
  FirstCriteria Criteria
  OtherCriteria Criteria
}

func (r *OrCriteria) Filter(persons []*Person) []*Person {
  var firstCriteriaItems = r.FirstCriteria.Filter(persons)
  var otherCriteriaItems = r.OtherCriteria.Filter(persons)

  for _, person := range otherCriteriaItems {
    if !person.IsContained(firstCriteriaItems) {
      firstCriteriaItems = append(firstCriteriaItems, person)
    }
  }
  return firstCriteriaItems
}
