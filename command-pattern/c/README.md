## 代码结构
```shell
- src
  - func.h # 头文件，定义接口与数据
  - command.c # 命令抽象类或接口，定义在头文件
  - buy_command.c # 具体命令类之一，继承或实现抽象接口
  - sell_command.c # 具体命令类之一，继承或实现抽象接口
  - command_invoker.c # 命令调用类，通过关联命令来执行命令的调用
  - stock_receiver.c # 命令模式真正的执行类，由command来调用
```

## 测试验证

```shell
$ cd ./command-pattern/go
$ gcc src/*.c test/test.c 
$ ./a.out
```
