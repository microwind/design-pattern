## 代码结构
```shell
- src
  - Expression.js # 定义表达式抽象类或接口
  - AddExpression.js # 具体表达式，实现或继承抽象表达式接口
  - SubtractExpression.js # 具体表达式，实现或继承抽象表达式接口
  - VarExpression.js.js # 具体表达式，实现或继承抽象表达式接口
  - Context.js # 构建可执行环境上下文，表达式在执行上下文解释
  - Application.js # 客户端调用，使用表达式
```

## 测试验证

```shell
$ cd ./interpreter-pattern/js
$ node test/test.js
```
