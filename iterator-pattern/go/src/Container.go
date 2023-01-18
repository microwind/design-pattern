package src

// 创建抽象容器接口，创建一个迭代器
type Container interface {
  CreateIterator() Iterator
}
