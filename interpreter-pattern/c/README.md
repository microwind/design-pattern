## 代码结构
```shell
- src
  - func.h # 头文件，定义接口与数据
  - expression.c # 抽象表达式接口，根据业务场景规范表达式，定义在head
  - add_expression.c # 具体表达式，实现或继承抽象表达式接口
  - subtract_expression.c # 具体表达式，实现或继承抽象表达式接口
  - var_expression.c.c # 具体表达式，实现或继承抽象表达式接口
  - context.c # 构建可执行环境上下文，表达式在执行上下文解释
  - application.c # 客户端调用，使用表达式
```

## 测试验证

```shell
$ cd ./interpreter-pattern/c
$ gcc test/test.c src/*.c
$ ./a.out
```
