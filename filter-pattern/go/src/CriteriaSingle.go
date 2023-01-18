package src

import (
  "strings"
)

// 根据标准接口实现的过滤
type CriteriaSingle struct {
}

// 根据是否单身进行过滤
func (c *CriteriaSingle) Filter(persons []*Person) []*Person {
  var singlePersons []*Person
  for _, person := range persons {
    if strings.ToUpper(person.GetStatus()) == "SINGLE" {
      singlePersons = append(singlePersons, person)
    }
  }
  return singlePersons
}
