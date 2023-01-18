package src

// 对象迭代器，实现了抽象迭代器的方法，聚合了数据对象
type ObjectIterator struct {
  // 迭代器索引
  index int
  // 聚合了数据对象
  objectList *ObjectList
}

func (o *ObjectIterator) HasNext() bool {
  if o.index < o.objectList.Size() {
    return true
  }
  return false
}

func (o *ObjectIterator) Next() string {
  if o.HasNext() {
    // 返回数据对象提供的get方法，每访问一次下标增加1位
    item := o.objectList.Get(o.index)
    o.index += 1
    return item
  }
  return ""
}
