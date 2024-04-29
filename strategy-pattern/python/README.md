## 代码结构
```shell
- src
  - Context.py # 抽象业务类，聚合策略对象
  - ContextCat.py # 具体的业务实现，可绑定某个策略
  - ContextDog.py # 具体的业务实现，可绑定某个策略
  - Strategy.py # 策略抽象接口，定义策略基本行为
  - StrategyA.py # 具体的策略实现者
  - StrategyB.py # 具体的策略实现者
  - StrategyC.py # 具体的策略实现者
```

## 测试验证

```shell
$ cd ./strategy-pattern/python
$ python test/test.py
```
