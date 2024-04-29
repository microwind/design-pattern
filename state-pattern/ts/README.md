## 代码结构
```shell
- src
  - Context.ts # 执行实体类，内部关联状态
  - State.ts # 定义抽象接口和状态方法，当前context只有一种状态
  - ConcreteStateOff.ts # 具体的状态实现者
  - ConcreteStateOn.ts # 具体的状态实现者
```

## 测试验证

```shell
$ cd ./state-pattern/ts
$ tsc
$ node test/test.js
```
