import { ObjectList } from '../src/ObjectList.js'

export function test() {
  /*
   * 迭代器模式是给数据容器创建单独的迭代器，用来遍历里面的数据对象
   * 数据容器和迭代器相互关联，外部通过迭代器来访问数据容器
   * 通过这种方式由迭代器类来负责数据遍历，这样可以做到不暴露集合的内部结构
   */
  let i = 0
  const objectList = new ObjectList()
  objectList.setObjects(['Thomas', 'Merry', 'Jack', 'Tony', 'Jerry', 'Joey'])
  // for循环迭代对象
  for (const iter = objectList.createIterator(); iter.hasNext();) {
    const name = iter.next()
    console.log('objectList[' + i + '] = ' + name)
    i++
  }

  // while循环迭代对象
  const iter2 = objectList.createIterator()
  objectList.setObjects([3, 5, 7, 9, 11])
  while (iter2.hasNext()) {
    console.log(iter2.next())
  }
}

// 执行测试
;(function () {
  console.log('test start:')
  test()
})()

/**
jarry@jarrys-MacBook-Pro ts % tsc
jarry@jarrys-MacBook-Pro ts % node test/test.js
test start:
ObjectList::createIterator() [获取迭代器 ObjectIterator]
objectList[0] = Thomas
objectList[1] = Merry
objectList[2] = Jack
objectList[3] = Tony
objectList[4] = Jerry
objectList[5] = Joey
ObjectList::createIterator() [获取迭代器 ObjectIterator]
3
5
7
9
11
*/
