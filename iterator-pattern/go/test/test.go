package main

import (
  "fmt"
  "strconv"

  "../src"
)

// main包下的main入口方法
func main() {
  fmt.Println("test start:")
  /*
   * 迭代器模式是给数据容器创建单独的迭代器，用来遍历里面的数据对象
   * 数据容器和迭代器相互关联，外部通过迭代器来访问数据容器
   * 通过这种方式由迭代器类来负责数据遍历，这样可以做到不暴露集合的内部结构
   */
  var i = 0
  var objectList = new(src.ObjectList)
  list := []string{"Thomas", "Merry", "Jack", "Tony", "Jerry", "Joey"}
  objectList.SetObjects(list)

  // for循环迭代对象
  for iter := objectList.CreateIterator(); iter.HasNext(); {
    name := iter.Next()
    fmt.Println("objectList[" + strconv.Itoa(i) + "] = " + name)
    i++
  }

  // 模拟while遍历
  var iter2 = objectList.CreateIterator()
  for iter2.HasNext() {
    fmt.Println(iter2.Next())
    if iter2.HasNext() == false {
      break
    }
  }

}

/**
jarry@jarrys-MacBook-Pro go % go build src/*.go
jarry@jarrys-MacBook-Pro go % go run test/test.go
test start:
ObjectList::CreateIterator() [获取迭代器 ObjectIterator]
objectList[0] = Thomas
objectList[1] = Merry
objectList[2] = Jack
objectList[3] = Tony
objectList[4] = Jerry
objectList[5] = Joey
ObjectList::CreateIterator() [获取迭代器 ObjectIterator]
Thomas
Merry
Jack
Tony
Jerry
Joey
*/
