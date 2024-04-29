## 代码结构
```shell
- src
  - Context.go # 执行实体类，内部关联状态
  - State.go # 定义抽象接口和状态方法，当前context只有一种状态
  - ConcreteStateOff.go # 具体的状态实现者
  - ConcreteStateOn.go # 具体的状态实现者
```

## 测试验证

```shell
$ cd ./state-pattern/go
$ go run test/test.go
```
