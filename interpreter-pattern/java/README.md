## 代码结构
```shell
- src
  - Expression.java # 定义表达式抽象类或接口
  - AddExpression.java # 具体表达式，实现或继承抽象表达式接口
  - SubtractExpression.java # 具体表达式，实现或继承抽象表达式接口
  - VarExpression.java.java # 具体表达式，实现或继承抽象表达式接口
  - Context.java # 构建可执行环境上下文，表达式在执行上下文解释
  - Application.java # 客户端调用，使用表达式
```

## 测试验证

```shell
$ cd ./interpreter-pattern/java
$ javac test/Test.java
$ java test/Test
```
