package src

// 定义抽象标准接口，聚合要过滤的对象集合
type Criteria interface {
  Filter(persons []*Person) []*Person
}
