package src

// 迭代器抽象接口，提供next和hasNext方法
type Iterator interface {
  HasNext() bool
  Next() string
}
