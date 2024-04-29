## 代码结构
```shell
- src
  - Context.go # 抽象业务类，聚合策略对象
  - ContextCat.go # 具体的业务实现，可绑定某个策略
  - ContextDog.go # 具体的业务实现，可绑定某个策略
  - Strategy.go # 策略抽象接口，定义策略基本行为
  - StrategyA.go # 具体的策略实现者
  - StrategyB.go # 具体的策略实现者
  - StrategyC.go # 具体的策略实现者
```

## 测试验证

```shell
$ cd ./strategy-pattern/go
$ go run test/test.go
```
