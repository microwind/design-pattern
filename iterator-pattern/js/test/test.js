import { ObjectList } from '../src/ObjectList.js'

export function test() {
  /*
   * 迭代器模式是给数据容器创建单独的迭代器，用来遍历里面的对象
   * 数据容器和迭代器相互关联，外部通过迭代器来访问数据容器
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
// npm run
jarry@jarrys-MacBook-Pro js % npm run test
// or node execution
jarry@jarrys-MacBook-Pro js % node test/test.js
test start:
ObjectList::createIterator() [获取迭代器 ObjectIterator]
objectList[0] = Thomas
objectList[1] = Merry
objectList[2] = Jack
objectList[3] = Tony
objectList[4] = Jerry
objectList[5] = Joey
ObjectList::createIterator() [获取迭代器 ObjectIterator]
Thomas
Merry
Jack
Tony
Jerry
Joey
*/
