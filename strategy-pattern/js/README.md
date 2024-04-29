## 代码结构
```shell
- src
  - Context.js # 抽象业务类，聚合策略对象
  - ContextCat.js # 具体的业务实现，可绑定某个策略
  - ContextDog.js # 具体的业务实现，可绑定某个策略
  - Strategy.js # 策略抽象接口，定义策略基本行为
  - StrategyA.js # 具体的策略实现者
  - StrategyB.js # 具体的策略实现者
  - StrategyC.js # 具体的策略实现者
```

## 测试验证

```shell
$ cd ./strategy-pattern/js
$ node test/test.js
```
