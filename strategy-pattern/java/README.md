## 代码结构
```shell
- src
  - Context.java # 抽象业务类，聚合策略对象
  - ContextCat.java # 具体的业务实现，可绑定某个策略
  - ContextDog.java # 具体的业务实现，可绑定某个策略
  - Strategy.java # 策略抽象接口，定义策略基本行为
  - StrategyA.java # 具体的策略实现者
  - StrategyB.java # 具体的策略实现者
  - StrategyC.java # 具体的策略实现者
```

## 测试验证

```shell
$ cd ./strategy-pattern/java
$ javac test/Test.java
$ java test/Test
```
