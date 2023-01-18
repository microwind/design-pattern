package src

import "fmt"

// 数据对象，是一种数据容器，实现了数据容器接口，可以创建一个迭代器
type ObjectList struct {
  // 内部的数据结构
  objects []string
}

func (o *ObjectList) CreateIterator() Iterator {
  fmt.Println("ObjectList::CreateIterator() [获取迭代器 ObjectIterator]")
  // 创建迭代器实例，绑定新建当前对象
  return &ObjectIterator{
    objectList: o,
  }
}

func (o *ObjectList) SetObjects(objects []string) {
  o.objects = objects
}

func (o *ObjectList) GetObjects() []string {
  return o.objects
}

func (o *ObjectList) Size() int {
  return len(o.objects)
}

func (o *ObjectList) Get(index int) string {
  return o.objects[index]
}
