package src

import "strings"

// 根据标准接口实现的过滤
type CriteriaMale struct {
}

// 根据是否男性进行过滤
func (r *CriteriaMale) Filter(persons []*Person) []*Person {
  var malePersons []*Person
  for _, person := range persons {
    if strings.ToUpper(person.GetGender()) == "MALE" {
      malePersons = append(malePersons, person)
    }
  }
  return malePersons
}
