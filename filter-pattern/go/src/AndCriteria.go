package src

// 定义And过滤标准
type AndCriteria struct {
  FirstCriteria Criteria
  OtherCriteria Criteria
}

// 先过滤条件1，再把结果按照条件2进行过滤
func (a *AndCriteria) Filter(persons []*Person) []*Person {
  var firstCriteriaPersons = a.FirstCriteria.Filter(persons)
  return a.OtherCriteria.Filter(firstCriteriaPersons)
}
