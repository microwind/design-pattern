## 代码结构
```shell
- src
  - Expression.py # 定义表达式抽象类或接口
  - AddExpression.py # 具体表达式，实现或继承抽象表达式接口
  - SubtractExpression.py # 具体表达式，实现或继承抽象表达式接口
  - VarExpression.py.py # 具体表达式，实现或继承抽象表达式接口
  - Context.py # 构建可执行环境上下文，表达式在执行上下文解释
  - Application.py # 客户端调用，使用表达式
```

## 测试验证

```shell
$ cd ./interpreter-pattern/python
$ python test/test.py
```
