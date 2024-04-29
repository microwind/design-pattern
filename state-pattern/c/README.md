## 代码结构
```shell
- src
  - func.h # 头文件，定义接口与数据
  - context.c # 执行实体类，内部关联状态。定义在head
  - state.c # 定义抽象接口和状态方法，当前context只有一种状态
  - concrete_state_off.c # 具体的状态实现者
  - concrete_state_on.c # 具体的状态实现者
```

## 测试验证

```shell
$ cd ./state-pattern/c
$ gcc test/test.c ./src/*.c
$ ./a.out
```
