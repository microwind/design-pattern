## 代码结构
```shell
- src
  - Context.ts # 抽象业务类，聚合策略对象
  - ContextCat.ts # 具体的业务实现，可绑定某个策略
  - ContextDog.ts # 具体的业务实现，可绑定某个策略
  - Strategy.ts # 策略抽象接口，定义策略基本行为
  - StrategyA.ts # 具体的策略实现者
  - StrategyB.ts # 具体的策略实现者
  - StrategyC.ts # 具体的策略实现者
```

## 测试验证

```shell
$ cd ./strategy-pattern/ts
$ tsc
$ node test/test.js
```
