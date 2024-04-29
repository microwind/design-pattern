## 代码结构
```shell
- src
  - Criteria.py # 定义抽象标准接口，聚合实体对象
  - AndCriteria.py # 定义And过滤标准，继承或实现抽象标准
  - OrCriteria.py # 定义Or过滤标准，继承或实现抽象标准
  - CriteriaFemale.py # 根据标准接口实现的过滤，继承或实现抽象标准
  - CriteriaMale.py # 根据标准接口实现的过滤，继承或实现抽象标准
  - CriteriaSingle # 根据标准接口实现的过滤，继承或实现抽象标准
  - Person.py # 定义实体类，用来过滤的对象
```

## 测试验证

```shell
$ cd ./filter-pattern/python
$ python test/test.py
```
