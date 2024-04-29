## 代码结构
```shell
- src
  - func.h # 头文件，定义接口与数据
  - criteria.c # 定义抽象标准接口，聚合实体对象
  - and_criteria.c # 定义And过滤标准，继承或实现抽象标准
  - or_criteria.c # 定义Or过滤标准，继承或实现抽象标准
  - criteria_female.c # 根据标准接口实现的过滤，继承或实现抽象标准
  - criteria_male.c # 根据标准接口实现的过滤，继承或实现抽象标准
  - criteria_single # 根据标准接口实现的过滤，继承或实现抽象标准
  - person.c # 定义实体类，用来过滤的对象
```

## 测试验证

```shell
$ cd ./filter-pattern/c
$ gcc test/test.c src*.c
$ ./a.out
```
