## 代码结构
```shell
- src
  - Container.java # 抽象容器接口，创建一个迭代器
  - Iterator.java # 迭代器抽象接口，提供next和hasNext方法
  - ObjectIterator.java # 对象迭代器，实现了抽象迭代器的方法，聚合了对象列表
  - ObjectList.java # 对象列表，是一种数据容器，可以创建一个迭代器
```

## 测试验证

```shell
$ cd ./iterator-pattern/java
$ javac test/Test.java
$ java test/Test
```
