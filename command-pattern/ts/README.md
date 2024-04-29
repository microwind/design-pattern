## 代码结构
```shell
- src
  - Command.ts # 命令抽象类或接口，定义基础命令接口
  - BuyCommand.ts # 具体命令类之一，继承或实现抽象接口
  - SellCommand.ts # 具体命令类之一，继承或实现抽象接口
  - CommandInvoker.ts # 命令调用类，通过关联命令来执行命令的调用
  - StockReceiver.ts # 命令模式真正的执行类，由command来调用
```

## 测试验证

```shell
$ cd ./command-pattern/ts
$ tsc
$ node test/test.js
```
