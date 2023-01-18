package src

import "strings"

// 根据标准接口实现的过滤
type CriteriaFemale struct {
}

// 根据是否女性进行过滤
func (r *CriteriaFemale) Filter(persons []*Person) []*Person {
  var femalePersons []*Person
  for _, person := range persons {
    if strings.ToUpper(person.GetGender()) == "FEMALE" {
      femalePersons = append(femalePersons, person)
    }
  }
  return femalePersons
}
