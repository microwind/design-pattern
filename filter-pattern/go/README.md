## 代码结构
```shell
- src
  - Criteria.go # 定义抽象标准接口，聚合实体对象
  - AndCriteria.go # 定义And过滤标准，继承或实现抽象标准
  - OrCriteria.go # 定义Or过滤标准，继承或实现抽象标准
  - CriteriaFemale.go # 根据标准接口实现的过滤，继承或实现抽象标准
  - CriteriaMale.go # 根据标准接口实现的过滤，继承或实现抽象标准
  - CriteriaSingle # 根据标准接口实现的过滤，继承或实现抽象标准
  - Person.go # 定义实体类，用来过滤的对象
```

## 测试验证

```shell
$ cd ./filter-pattern/go
$ go run test/test.go
```
