## 代码结构
```shell
- src
  - Context.java # 执行实体类，内部关联状态
  - State.java # 定义抽象接口和状态方法，当前context只有一种状态
  - ConcreteStateOff.java # 具体的状态实现者
  - ConcreteStateOn.java # 具体的状态实现者
```

## 测试验证

```shell
$ cd ./state-pattern/java
$ javac test/Test.java
$ java test/Test
```
