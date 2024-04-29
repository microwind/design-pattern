## 代码结构
```shell
- src
  - Context.py # 执行实体类，内部关联状态
  - State.py # 定义抽象接口和状态方法，当前context只有一种状态
  - ConcreteStateOff.py # 具体的状态实现者
  - ConcreteStateOn.py # 具体的状态实现者
  - ConcreteFactory.py # 为避免状态类之间import时相互循环依赖，将import延迟，并通过统一入口获取实例
```

## 测试验证

```shell
$ cd ./state-pattern/python
$ python test/test.py
```
