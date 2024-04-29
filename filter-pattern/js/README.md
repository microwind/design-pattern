## 代码结构
```shell
- src
  - Criteria.js # 定义抽象标准接口，聚合实体对象
  - AndCriteria.js # 定义And过滤标准，继承或实现抽象标准
  - OrCriteria.js # 定义Or过滤标准，继承或实现抽象标准
  - CriteriaFemale.js # 根据标准接口实现的过滤，继承或实现抽象标准
  - CriteriaMale.js # 根据标准接口实现的过滤，继承或实现抽象标准
  - CriteriaSingle # 根据标准接口实现的过滤，继承或实现抽象标准
  - Person.js # 定义实体类，用来过滤的对象
```

## 测试验证

```shell
$ cd ./filter-pattern/js
$ node test/test.js
```
