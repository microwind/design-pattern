## 代码结构
```shell
- src
  - func.h # 头文件，定义接口与数据
  - container.c # 抽象容器struct，定义在head，可选
  - iterator.c # 迭代器抽象接口，约定next和has_next方法，定义在head
  - object_iterator.c # 对象迭代器，实现了抽象迭代器的方法，聚合了对象列表
  - object_list.c # 对象列表，是一种数据容器，可以创建一个迭代器
```

## 测试验证

```shell
$ cd ./iterator-pattern/js
$ gcc test/test.c src/*.c
$ ./a.out
```
