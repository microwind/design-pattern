## 代码结构
```shell
- src
  - Criteria.ts # 定义抽象标准接口，聚合实体对象
  - AndCriteria.ts # 定义And过滤标准，继承或实现抽象标准
  - OrCriteria.ts # 定义Or过滤标准，继承或实现抽象标准
  - CriteriaFemale.ts # 根据标准接口实现的过滤，继承或实现抽象标准
  - CriteriaMale.ts # 根据标准接口实现的过滤，继承或实现抽象标准
  - CriteriaSingle # 根据标准接口实现的过滤，继承或实现抽象标准
  - Person.ts # 定义实体类，用来过滤的对象
```

## 测试验证

```shell
$ cd ./filter-pattern/ts
$ tsc
$ node test/test.js
```
