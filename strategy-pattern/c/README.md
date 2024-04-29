## 代码结构
```shell
- src
  - func.h # 头文件，定义接口与数据
  - context.c # 抽象业务类，聚合策略对象
  - context_cat.c # 具体的业务实现，可绑定某个策略
  - context_dog.c # 具体的业务实现，可绑定某个策略
  - strategy.c # 策略抽象接口，定义在head文件
  - strategy_a.c # 具体的策略实现者
  - strategy_b.c # 具体的策略实现者
  - strategy_c.c # 具体的策略实现者
```

## 测试验证

```shell
$ cd ./strategy-pattern/c
$ gcc test/test.c ./src/*.c
$ ./a.out
```
