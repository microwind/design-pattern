## 代码结构
```shell
- src
  - Expression.ts # 定义表达式抽象类或接口
  - AddExpression.ts # 具体表达式，实现或继承抽象表达式接口
  - SubtractExpression.ts # 具体表达式，实现或继承抽象表达式接口
  - VarExpression.ts.ts # 具体表达式，实现或继承抽象表达式接口
  - Context.ts # 构建可执行环境上下文，表达式在执行上下文解释
  - Application.ts # 客户端调用，使用表达式
```

## 测试验证

```shell
$ cd ./interpreter-pattern/ts
$ node test/test.js
```
